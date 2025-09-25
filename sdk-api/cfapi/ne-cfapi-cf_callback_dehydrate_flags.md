# CF_CALLBACK_DEHYDRATE_FLAGS enumeration

## Description

Callback flags for notifying a sync provider that a placeholder under one of its sync root is going to be dehydrated.

## Constants

### `CF_CALLBACK_DEHYDRATE_FLAG_NONE:0x00000000`

No dehydrate flag.

### `CF_CALLBACK_DEHYDRATE_FLAG_BACKGROUND:0x00000001`

A flag set if the dehydration request is initiated by a system background service.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)