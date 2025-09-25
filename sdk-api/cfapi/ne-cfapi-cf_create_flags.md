# CF_CREATE_FLAGS enumeration

## Description

Flags for creating a placeholder file or directory.

## Constants

### `CF_CREATE_FLAG_NONE:0x00000000`

Default mode. All entries are processed.

### `CF_CREATE_FLAG_STOP_ON_ERROR:0x00000001`

Causes the API to return immediately if placeholder creation fails. If creation fails, the error code will be returned by the API.

## See also

[CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders)