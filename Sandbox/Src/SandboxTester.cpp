// Copyright (c) 2020 [Untitled Games]
// This file is subject to the terms and conditions defined in
// file 'LICENSE', which is part of this source code package.
// 
// [+ :]

#include <UntitledEngine.h>
#include <iostream>

class Sandbox : public ue::Application {
public:
	Sandbox() {
		std::cout << "Starting UE Application..." << std::endl;
	}
};

ue::Application* ue::CreateApplication() { return new Sandbox(); }
