// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#include "uepch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ue {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

	std::shared_ptr<spdlog::logger> Log::s_AppLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_AppLogger = spdlog::stdout_color_mt("APP");
		s_AppLogger->set_level(spdlog::level::trace);
	}

}
