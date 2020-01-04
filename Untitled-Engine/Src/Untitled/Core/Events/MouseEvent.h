// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#include "Event.h"

namespace ue {

	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) {}
		MouseMovedEvent() = delete;
		_NODISCARD inline float GetMouseX() const { return m_MouseX; }
		_NODISCARD inline float GetMouseY() const { return m_MouseY; }
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryKeyboard) | int(EventCategory::EventCategoryInput))
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset) : m_OffsetX(xOffset), m_OffsetY(yOffset) {}
		MouseScrolledEvent() = delete;
		_NODISCARD inline float GetOffsetX() const { return m_OffsetX; }
		_NODISCARD inline float GetOffsetY() const { return m_OffsetY; }
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryMouse) | int(EventCategory::EventCategoryInput))
	private:
		float m_OffsetX, m_OffsetY;
	};

	class MouseButtonEvent : public Event {
	public:
		MouseButtonEvent(const int button) : m_Button(button) {}
		MouseButtonEvent() = delete;
		_NODISCARD inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryMouse) | int(EventCategory::EventCategoryInput))
	protected:
		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(const int button, const int repeatCount) : MouseButtonEvent(button), m_RepeatCount(repeatCount) {}

		MouseButtonPressedEvent() = delete;
		_NODISCARD inline int GetRepeatCount() const { return m_RepeatCount; }
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		int m_RepeatCount;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const int button) : MouseButtonEvent(button) {}
		MouseButtonReleasedEvent() = delete;
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
