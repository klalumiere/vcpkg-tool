#pragma once
#include "PostBuildLint_ConfigurationType.h"
#include "PostBuildLint_LinkageType.h"
#include <array>
#include <regex>

namespace vcpkg::PostBuildLint::BuildType
{
    enum class BackingEnum
    {
        DEBUG_STATIC = 1,
        DEBUG_DYNAMIC,
        RELEASE_STATIC,
        RELEASE_DYNAMIC
    };

    struct Type
    {
        Type() = delete;

        constexpr explicit Type(const BackingEnum backing_enum, const ConfigurationType::type config, const LinkageType::type linkage) :
            backing_enum(backing_enum), m_config(config), m_linkage(linkage) { }

        constexpr operator BackingEnum() const { return backing_enum; }

        const ConfigurationType::type& config() const;
        const LinkageType::type& linkage() const;
        const std::regex& crt_regex() const;
        const std::string& toString() const;

    private:
        BackingEnum backing_enum;
        ConfigurationType::type m_config;
        LinkageType::type m_linkage;
    };

    static const std::string ENUM_NAME = "vcpkg::PostBuildLint::BuildType";

    static constexpr Type DEBUG_STATIC = Type(BackingEnum::DEBUG_STATIC, ConfigurationType::DEBUG, LinkageType::STATIC);
    static constexpr Type DEBUG_DYNAMIC = Type(BackingEnum::DEBUG_DYNAMIC, ConfigurationType::DEBUG, LinkageType::DYNAMIC);
    static constexpr Type RELEASE_STATIC = Type(BackingEnum::RELEASE_STATIC, ConfigurationType::RELEASE, LinkageType::STATIC);
    static constexpr Type RELEASE_DYNAMIC = Type(BackingEnum::RELEASE_DYNAMIC, ConfigurationType::RELEASE, LinkageType::DYNAMIC);

    static constexpr std::array<Type, 4> values = { DEBUG_STATIC, DEBUG_DYNAMIC, RELEASE_STATIC, RELEASE_DYNAMIC };

    Type value_of(const ConfigurationType::type& config, const LinkageType::type& linkage);
}
