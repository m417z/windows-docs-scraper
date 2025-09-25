# CF_CALLBACK_DELETE_FLAGS enumeration

## Description

This enum is used by `CF_CALLBACK_TYPE_NOTIFY_DELETE` (see [CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)) when informing the sync provider that a placeholder file or directory under one of its sync roots is about to be deleted or undeleted.

## Constants

### `CF_CALLBACK_DELETE_FLAG_NONE`

`0x00000000`

No delete flag.

### `CF_CALLBACK_DELETE_FLAG_IS_DIRECTORY`

`0x00000001`

The placeholder that is about to be deleted is a directory.

### `CF_CALLBACK_DELETE_FLAG_IS_UNDELETE`

`0x00000002`

The placeholder is being undeleted.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)