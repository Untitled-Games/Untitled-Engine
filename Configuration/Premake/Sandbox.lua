-- Copyright (c) 2020 [Untitled Games]
-- This file is subject to the terms and conditions defined in
-- file 'LICENSE', which is part of this source code package.
-- 
-- [+ :]

project "Sandbox"
	location "../../Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Bin-Intermediate/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.location}/Src/**.h",
		"%{prj.location}/Src/**.cpp"
	}

	includedirs {
		(ue_root_dir .. "/Src"),
		(ue_root_dir .. "/Dependencies"),
		"%{includes.spdlog}",
		"%{includes.glm}"
	}

	links {
		"Untitled-Engine"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"UE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "UE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "UE_DIST"
		runtime "Release"
		optimize "On"
