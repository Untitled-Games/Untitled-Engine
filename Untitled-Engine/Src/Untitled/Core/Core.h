// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#pragma once

#ifdef UE_DEBUG
#define UE_ENABLE_ASSERTS
#endif

#ifdef UE_ENABLE_ASSERTS
#define UE_ASSERT(x, ...) { if(!(x)) { UE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define UE_ASSERT(x, ...)
#endif
