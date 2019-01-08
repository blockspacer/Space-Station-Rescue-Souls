#pragma once
#include "BaseSystem.h"

namespace app::sys 
{
	/// <summary>
	/// @class Class that responds to input.
	/// </summary>
	class ControlSystem :
		public BaseSystem
	{
	public:
		ControlSystem(const app::inp::KeyHandler & keyhandler);
		virtual void update(app::time::seconds const & dt) override;
		void spawnBullet(math::Vector2f position, float angle, bool firedByPlayer);

		~ControlSystem();

		/// <summary>
		/// @brief constant reference to a keyhandler of the game.
		/// 
		/// 
		/// </summary>
		const app::inp::KeyHandler & m_keyHandler;

		/// <summary>
		/// @brief the angle in degrees at which to rotate by.
		/// 
		/// 
		/// </summary>
		const float m_rotate;

	};
}


