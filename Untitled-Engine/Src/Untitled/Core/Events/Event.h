// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#include <string>

#define BIT(x) (1 << x)

namespace ue {

	enum class EventType {
		None = 0,
		WindowClosed, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseMoved, MouseScrolled,
		MouseButtonPressed, MouseButtonReleased
	};

	enum class EventCategory {
		None = 0,
		EventCategoryApplication =	BIT(0),
		EventCategoryInput =		BIT(1),
		EventCategoryKeyboard =		BIT(2),
		EventCategoryMouse =		BIT(3),
		EventCategoryMouseButton =	BIT(4)
	};
	
	class Event {
		friend class EventDispatcher;
	public:
		_NODISCARD bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & int(category); }
		_NODISCARD bool IsHandled() const { return m_Handled; }
		void SetHandled(const bool value) { m_Handled = value; }
		_NODISCARD virtual EventType GetEventType() const = 0;
		_NODISCARD virtual int GetCategoryFlags() const = 0;
		_NODISCARD virtual const char* GetName() const = 0;
		_NODISCARD virtual std::string ToString() const { return GetName(); }
	private:
		bool m_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
	virtual EventType GetEventType() const override { return GetStaticType(); }	\
	virtual const char* GetName() const override { return #type; }

}
