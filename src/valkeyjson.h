/*
* Copyright (C) 2016-2017 Redis Labs
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __VALKEYJSON_H__
#define __VALKEYJSON_H__

#include <logging.h>
#include <sds.h>
#include <string.h>
#include <strings.h>
#include <util.h>
#include "json_object.h"
#include "json_path.h"
#include "object.h"
#include "json_type.h"
#include "valkeymodule.h"
#include "version.h"

#define VKMODULE_NAME "ValkeyJSON"
#define VKMODULE_DESC "JSON data type for Valkey"

#define VKM_ERRORMSG_SYNTAX "ERR syntax error"

#define VALKEYJSON_ERROR_EMPTY_STRING "ERR the empty string is not a valid JSON value"
#define VALKEYJSON_ERROR_JSONOBJECT_ERROR "ERR unspecified json_object error (probably OOM)"
#define VALKEYJSON_ERROR_SERIALIZE "ERR object serialization to JSON failed"
#define VALKEYJSON_ERROR_NEW_NOT_ROOT "ERR new objects must be created at the root"
#define VALKEYJSON_ERROR_PATH_NANTYPE "ERR wrong type of path value - expected a number but found %s"
#define VALKEYJSON_ERROR_PATH_WRONGTYPE "ERR wrong type of path value - expected %s but found %s"
#define VALKEYJSON_ERROR_PATH_NONTERMINAL_KEY "ERR missing key at non-terminal path level"
#define VALKEYJSON_ERROR_INDEX_INVALID "ERR array index must be an integer"
#define VALKEYJSON_ERROR_INDEX_OUTOFRANGE "ERR index out of range"
#define VALKEYJSON_ERROR_VALUE_NAN "ERR value is not a number type"
#define VALKEYJSON_ERROR_RESULT_NAN_OR_INF "ERR result is not a number or an infinty"
#define VALKEYJSON_ERROR_DICT_SET "ERR could not set key in dictionary"
#define VALKEYJSON_ERROR_ARRAY_SET "ERR could not set item in array"
#define VALKEYJSON_ERROR_ARRAY_GET "ERR could not get item from array"
#define VALKEYJSON_ERROR_DICT_DEL "ERR could not delete from dictionary"
#define VALKEYJSON_ERROR_ARRAY_DEL "ERR could not delete from array"
#define VALKEYJSON_ERROR_INSERT "ERR could not insert into array"
#define VALKEYJSON_ERROR_INSERT_SUBARRY "ERR could not prepare the insert operation"
#define VALKEYJSON_ERROR_KEY_REQUIRED "ERR could not perform this operation on a key that doesn't exist"

#endif
