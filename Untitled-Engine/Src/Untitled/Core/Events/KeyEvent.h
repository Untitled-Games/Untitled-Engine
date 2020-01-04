// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#include "Event.h"

namespace ue
{

	class KeyEvent : public Event
	{
	public:
		KeyEvent(const int keycode) : m_KeyCode(keycode) {}
		KeyEvent() = delete;
		_NODISCARD inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(int(EventCategory::EventCategoryKeyboard) | int(EventCategory::EventCategoryInput))
	protected:
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keycode, const int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		KeyPressedEvent() = delete;
		_NODISCARD inline int GetRepeatCount() const { return m_RepeatCount; }
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int keycode) : KeyEvent(keycode) {}
		KeyReleasedEvent() = delete;
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const int keycode) : KeyEvent(keycode) {}
		KeyTypedEvent() = delete;
		_NODISCARD std::string ToString() const override;
		EVENT_CLASS_TYPE(KeyTyped)
	};
}