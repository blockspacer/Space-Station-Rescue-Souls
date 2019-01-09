﻿#include "stdafx.h"
#include "CameraFollowSystem.h"

// components
#include "component/Camera.h"
#include "component/Location.h"

void app::sys::CameraFollowSystem::update(app::time::seconds const & dt)
{
	constexpr auto FOLLOW_DISTANCE = 0.02f;
	auto & camera = m_registry.get<comp::Camera>();
	if (!camera.entity.has_value()) { return; }
	auto & location = m_registry.get<comp::Location>(camera.entity.value());

	auto const & distance = location.position - camera.position;
	auto const & magnitudeDistance = distance.magnitude();
	if (magnitudeDistance > FOLLOW_DISTANCE)
	{
		auto const & speed = magnitudeDistance * 30.0f;
		auto const & direction = distance.unit();
		// move in direction of followLocation speed per second.
		camera.position += direction * speed * dt.count();
	}
}
