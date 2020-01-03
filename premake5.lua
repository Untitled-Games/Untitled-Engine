-- Copyright (c) 2020 [Untitled Games]
-- This file is subject to the terms and conditions defined in
-- file 'LICENSE', which is part of this source code package.
-- 
-- [+ :]

workspace "Untitled-Engine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include dependencies --
    if not ue_root_dir then
        ue_root_dir = "%{wks.location}/Untitled-Engine"
    end

    includes = {}
    includes["spdlog"] = (ue_root_dir .. "/Dependencies/SpdLog/include")
    includes["glfw"] = (ue_root_dir .. "/Dependencies/GLFW/include")
    includes["glm"] = (ue_root_dir .. "/Dependencies/GLM")
    includes["tinyobjloader"] = (ue_root_dir .. "/Dependencies/TinyObjLoader")

    -- Dependency projects --
    include "Configuration/Premake/GLFW.lua"

    -- Untitled Engine project --
    -- Requires: glfw
    include "Configuration/Premake/Untitled-Engine.lua"

    -- Sandbox project --
    -- Requires: Untitled-Engine
    include "Configuration/Premake/Sandbox.lua"
