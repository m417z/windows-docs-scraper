# CF_CALLBACK_RENAME_FLAGS enumeration

## Description

Callback flags to inform the sync provider that a placeholder under one of its sync roots is about to be renamed or moved.

## Constants

### `CF_CALLBACK_RENAME_FLAG_NONE:0x00000000`

No rename flag.

### `CF_CALLBACK_RENAME_FLAG_IS_DIRECTORY:0x00000001`

Flag set if the placeholder is a directory.

### `CF_CALLBACK_RENAME_FLAG_SOURCE_IN_SCOPE:0x00000002`

Flag set if the link to be renamed or moved is within a sync root managed by the sync process.

### `CF_CALLBACK_RENAME_FLAG_TARGET_IN_SCOPE:0x00000004`

Flag set if the rename or move target is in the same sync root of the source path.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)