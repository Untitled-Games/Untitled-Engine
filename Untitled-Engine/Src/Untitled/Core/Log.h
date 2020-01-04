// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#include <spdlog/spdlog.h>

namespace ue {

	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

		static std::shared_ptr<spdlog::logger> s_AppLogger;
	};

}

#ifdef UE_DEBUG

#define UE_LOG_TRACE(...)    ::ue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UE_LOG_INFO(...)     ::ue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UE_LOG_WARN(...)     ::ue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UE_LOG_ERROR(...)    ::ue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UE_LOG_FATAL(...)    ::ue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define UE_APP_TRACE(...)    ::ue::Log::GetAppLogger()->trace(__VA_ARGS__)
#define UE_APP_INFO(...)     ::ue::Log::GetAppLogger()->info(__VA_ARGS__)
#define UE_APP_WARN(...)     ::ue::Log::GetAppLogger()->warn(__VA_ARGS__)
#define UE_APP_ERROR(...)    ::ue::Log::GetAppLogger()->error(__VA_ARGS__)
#define UE_APP_FATAL(...)    ::ue::Log::GetAppLogger()->fatal(__VA_ARGS__)

#else

#define UE_LOG_TRACE(...)
#define UE_LOG_INFO(...)
#define UE_LOG_WARN(...)
#define UE_LOG_ERROR(...)
#define UE_LOG_FATAL(...)

#define UE_APP_TRACE(...)
#define UE_APP_INFO(...)
#define UE_APP_WARN(...)
#define UE_APP_ERROR(...)
#define UE_APP_FATAL(...)

#endif
