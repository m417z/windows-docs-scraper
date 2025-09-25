# PERCEIVED enumeration

## Description

Specifies a file's perceived type. This set of constants is used in the [AssocGetPerceivedType](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-assocgetperceivedtype) function.

## Constants

### `PERCEIVED_TYPE_FIRST:-3`

### `PERCEIVED_TYPE_CUSTOM:-3`

The file's perceived type as defined in the registry is not a known type.

### `PERCEIVED_TYPE_UNSPECIFIED:-2`

The file does not have a perceived type.

### `PERCEIVED_TYPE_FOLDER:-1`

Not used.

### `PERCEIVED_TYPE_UNKNOWN:0`

The file's perceived type hasn't yet been requested. This is the cached type of the object when it is created. This value is never returned by [AssocGetPerceivedType](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-assocgetperceivedtype).

### `PERCEIVED_TYPE_TEXT:1`

The file's perceived type is "text".

### `PERCEIVED_TYPE_IMAGE:2`

The file's perceived type is "image".

### `PERCEIVED_TYPE_AUDIO:3`

The file's perceived type is "audio".

### `PERCEIVED_TYPE_VIDEO:4`

The file's perceived type is "video".

### `PERCEIVED_TYPE_COMPRESSED:5`

The file's perceived type is "compressed".

### `PERCEIVED_TYPE_DOCUMENT:6`

The file's perceived type is "document".

### `PERCEIVED_TYPE_SYSTEM:7`

The file's perceived type is "system".

### `PERCEIVED_TYPE_APPLICATION:8`

The file's perceived type is "application".

### `PERCEIVED_TYPE_GAMEMEDIA:9`

**Windows Vista and later**. The file's perceived type is "gamemedia".

### `PERCEIVED_TYPE_CONTACTS:10`

**Windows Vista and later**.The file's perceived type is "contacts"

### `PERCEIVED_TYPE_LAST:10`

## Remarks

Prior to Windows Vista, this enumeration was declared in Shlwapi.h.