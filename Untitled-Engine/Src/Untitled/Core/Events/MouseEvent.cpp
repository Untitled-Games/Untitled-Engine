// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#include "uepch.h"

#include "MouseEvent.h"

namespace ue {

	std::string MouseMovedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	std::string MouseScrolledEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
		return ss.str();
	}

	std::string MouseButtonPressedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button << " (" << m_RepeatCount << " Repeats)";
		return ss.str();
	}

	std::string MouseButtonReleasedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}

}
