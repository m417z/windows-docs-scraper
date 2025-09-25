# CF_CALLBACK_DEHYDRATE_COMPLETION_FLAGS enumeration

## Description

A callback flag to inform the sync provider that a placeholder under one of its sync roots has been successfully dehydrated.

## Constants

### `CF_CALLBACK_DEHYDRATE_COMPLETION_FLAG_NONE:0x00000000`

No dehydration completion flag.

### `CF_CALLBACK_DEHYDRATE_COMPLETION_FLAG_BACKGROUND:0x00000001`

A flag set if the dehydration request is initiated by a system background service.

### `CF_CALLBACK_DEHYDRATE_COMPLETION_FLAG_DEHYDRATED:0x00000002`

A flag set if the placeholder was hydrated prior to the dehydration request.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)