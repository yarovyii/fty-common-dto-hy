/*  =========================================================================
    fty_srr_dto - Fty srr dto

    Copyright (C) 2014 - 2018 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
 */

#ifndef FTY_SRR_DTO_H_INCLUDED
#define FTY_SRR_DTO_H_INCLUDED

#include <string>
#include <list>

#include <fty_common_messagebus.h>

namespace dto
{
    namespace config
    {
        /**
         * Config request object
         */
        struct ConfigQueryDto {
            std::string action;
            std::string featureName;
            std::string data;

            ConfigQueryDto() = default;
            ConfigQueryDto(const std::string action) : action(action) {}
            ConfigQueryDto(const std::string action, const std::string featureName) : action(action), featureName(featureName) {}
            ConfigQueryDto(const std::string action, const std::string featureName, const std::string data) :
                action(action),
                featureName(featureName),
                data(data) {}
        };

        void operator<<(messagebus::UserData &data, const ConfigQueryDto &object);
        void operator>>(messagebus::UserData &inputData, ConfigQueryDto &object);

        /**
         * Config response object
         */
        struct ConfigResponseDto {
            std::string status;
            std::string data;
            std::string error;

            ConfigResponseDto() = default;
            ConfigResponseDto(const std::string status) : status(status) {}
            ConfigResponseDto(const std::string status, const std::string data) : status(status), data(data) {}
            ConfigResponseDto(const std::string status, const std::string data, const std::string error) : status(status), data(data), error(error) {}
        };

        void operator<<(messagebus::UserData &data, const ConfigResponseDto &object);
        void operator>>(messagebus::UserData &inputData, ConfigResponseDto &object);
        
    } // config namespace
    
} // dto namespace

#endif
