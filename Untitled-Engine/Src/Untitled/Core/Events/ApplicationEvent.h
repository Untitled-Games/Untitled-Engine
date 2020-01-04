// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#include "Event.h"

namespace ue {
	
	class WindowClosedEvent : public Event {
	public:
		WindowClosedEvent() = default;
		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryApplication))
	};

	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint32_t width, uint32_t height) : m_Width(width), m_Height(height) {}
		_NODISCARD uint32_t GetWidth() const { return m_Width; }
		_NODISCARD uint32_t GetHeight() const { return m_Height; }
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryApplication))
	private:
		uint32_t m_Width, m_Height;
	};

	class AppTickEvent : public Event {
	public:
		AppTickEvent() = default;
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryApplication))
	};

	class AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryApplication))
	};

	class AppRenderEvent : public Event {
	public:
		AppRenderEvent() = default;
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryApplication))
	};

}
