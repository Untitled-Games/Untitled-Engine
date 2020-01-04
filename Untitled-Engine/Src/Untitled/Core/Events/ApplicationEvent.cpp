// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#include "uepch.h"

#include "ApplicationEvent.h"

namespace ue {

	std::string WindowResizeEvent::ToString() const {
		std::stringstream ss;
		ss << "WindowResizeEvent: width:" << m_Width << ", height:" << m_Height;
		return ss.str();
	}
	
}
