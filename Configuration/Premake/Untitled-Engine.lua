-- Copyright (c) 2020 [Untitled Games]
-- This file is subject to the terms and conditions defined in
-- file 'LICENSE', which is part of this source code package.
-- 
-- [+ :]

project "Untitled-Engine"
    location (ue_root_dir)
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Intermediate/" .. outputdir .. "/%{prj.name}")

    pchheader "uepch.h"
    pchsource "%{prj.location}/Src/uepch.cpp"

    files {
        "%{prj.location}/Src/**.h",
        "%{prj.location}/Src/**.cpp",
        "%{prj.location}/Dependencies/TinyObjLoader/**.h",
        "%{prj.location}/Dependencies/TinyObjLoader/**.cpp",
        "%{prj.location}/Dependencies/GLM/glm/**.hpp",
        "%{prj.location}/Dependencies/GLM/glm/**.inl"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS",
        ("UE_RESOURCES=\"%{prj.location}/Resources/\"")
    }

    includedirs {
        "%{prj.location}/Src",
        "%{includes.spdlog}",
        "%{includes.glfw}",
        "%{includes.glm}",
        "%{includes.tinyobjloader}"
    }

    links {
        "GLFW"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "UE_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
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
