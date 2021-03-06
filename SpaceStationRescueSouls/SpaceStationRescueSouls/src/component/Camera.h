﻿#ifndef _COMPONENT_CAMERA_H
#define _COMPONENT_CAMERA_H

namespace app::comp
{
	/// 
	/// @brief Component Tag meant to represent a cameras data.
	/// @author Rafael Plugge
	/// 
	/// <summary>
	/// </summary>
	struct Camera
	{
	public: // Constructors/Destructor/Assignments
		Camera() = default;
		~Camera() = default;

		Camera(Camera const &) = default;
		Camera & operator=(Camera const &) = default;

		Camera(Camera &&) = default;
		Camera & operator=(Camera &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables

		/// 
		/// @brief Represents the entity that we will follow.
		/// 
		/// <summary>
		/// Defined optionally since our camera will support not having a entity.
		/// </summary>
		std::optional<app::Entity> entity;

		/// 
		/// @brief Represents the position that the camera is centered on.
		/// 
		/// <summary>
		/// </summary>
		math::Vector2f position = { 0.0f, 0.0f };

		/// 
		/// @brief Defines the viewports size.
		/// 
		/// <summary>
		/// </summary>
		math::Vector2f size = { 0.0f, 0.0f };

		/// 
		/// @brief Defines the offset of the camera from center position.
		/// 
		/// <summary>
		/// </summary>
		math::Vector2f offset = { 0.0f, 0.0f };

		struct
		{
			float x = 0.0f
				, y = 0.0f
				, w = 0.0f
				, h = 0.0f;
		}viewport;

		/// 
		/// @brief Whether to fill in the background.
		/// 
		/// <summary>
		/// </summary>
		bool fillBackground = false;

		/// 
		/// @brief Specifies whether its a radar.
		/// 
		/// <summary>
		/// </summary>
		bool isRadar = false;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_COMPONENT_CAMERA_H
