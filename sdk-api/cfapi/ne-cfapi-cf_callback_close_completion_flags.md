# CF_CALLBACK_CLOSE_COMPLETION_FLAGS enumeration

## Description

Callback flags for notifying a sync provider that a placeholder under one of its sync roots that has been previously opened for read/write/delete access is now closed.

## Constants

### `CF_CALLBACK_CLOSE_COMPLETION_FLAG_NONE:0x00000000`

No close completion flags.

### `CF_CALLBACK_CLOSE_COMPLETION_FLAG_DELETED:0x00000001`

A flag set if a placeholder is deleted as a result of the close.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)