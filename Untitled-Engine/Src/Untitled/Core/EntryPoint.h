// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#ifdef UE_PLATFORM_WINDOWS

int main(int argc, char** argv) {
	ue::Log::Init();

	UE_LOG_TRACE("Starting Engine...");

	ue::Application* app = ue::CreateApplication();
	const int returnCode = app->Run();
	delete app;

	return returnCode;
}

#else
#error Untitled Engine currently only supports Windows
#endif
