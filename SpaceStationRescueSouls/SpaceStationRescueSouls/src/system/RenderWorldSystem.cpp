﻿#include "stdafx.h"
#include "RenderWorldSystem.h"

// components
#include "component/RenderWorld.h"
#include "component/Camera.h"

#include "visitor/RenderFillVisitor.h"

app::sys::RenderWorldSystem::RenderWorldSystem(gra::Window & window)
	: BaseSystem()
	, m_window(window)
	, m_renderShape()
	, m_view()
{
}

void app::sys::RenderWorldSystem::update(app::time::seconds const & dt)
{
	auto & renderWorld = m_registry.get<comp::RenderWorld>();
	m_registry.view<comp::Camera>()
		.each([&, this](app::Entity const entity, comp::Camera & camera)
	{
		m_view.setCenter(camera.position + camera.offset);
		m_view.setSize(camera.size);
		m_view.setViewport({ camera.viewport.x, camera.viewport.y, camera.viewport.w, camera.viewport.h });
		m_window.setView(m_view);
		for (auto & section : renderWorld.sections)
		{
			m_renderShape.setPosition(section.position);
			m_renderShape.setSize(section.size);
			std::visit(vis::RenderFillVisitor(m_renderShape), section.fill);
			m_window.draw(m_renderShape);
		}
		m_window.resetView();
	});
}
