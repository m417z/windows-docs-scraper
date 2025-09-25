# CF_CALLBACK_OPEN_COMPLETION_FLAGS enumeration

## Description

Callback flags for notifying a sync provider that a placeholder was successfully opened for read/write/delete access.

## Constants

### `CF_CALLBACK_OPEN_COMPLETION_FLAG_NONE:0x00000000`

No open completion flag.

### `CF_CALLBACK_OPEN_COMPLETION_FLAG_PLACEHOLDER_UNKNOWN:0x00000001`

A flag set if the placeholder metadata is corrupted.

### `CF_CALLBACK_OPEN_COMPLETION_FLAG_PLACEHOLDER_UNSUPPORTED:0x00000002`

A flag set if the placeholder metadata is of an older and unsupported version.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)