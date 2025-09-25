# CF_PLACEHOLDER_CREATE_FLAGS enumeration

## Description

Flags for creating a placeholder on a per-placeholder basis.

## Constants

### `CF_PLACEHOLDER_CREATE_FLAG_NONE:0x00000000`

No placeholder create flags.

### `CF_PLACEHOLDER_CREATE_FLAG_DISABLE_ON_DEMAND_POPULATION:0x00000001`

When the flag is present, the newly created child placeholder directory is considered to have all of its children present locally hence accessing it in the future will not trigger any **FETCH_PLACEHOLDERS** callback on it. When the flag is absent, the newly created placeholder directory is considered partial and future access will trigger **FETCH_PLACEHOLDERS**. This flag is applicable to a child placeholder directory only.

### `CF_PLACEHOLDER_CREATE_FLAG_MARK_IN_SYNC:0x00000002`

The newly created placeholder is marked as in-sync as part of the **TRANSFER_PLACEHOLDERS** operation. This is applicable to both placeholder files and directories.

### `CF_PLACEHOLDER_CREATE_FLAG_SUPERSEDE:0x00000004`

The newly created placeholder will supercede/overwrite the an existing placeholder.

### `CF_PLACEHOLDER_CREATE_FLAG_ALWAYS_FULL:0x00000008`

When this flag is present, the newly created placeholder will be marked as always full. Once hydrated, any attempt to dehydrate such a (file) placeholder will fail with error code **ERROR_CLOUD_FILE_DEHYDRATION_DISALLOWED**. This flag is enforced on a placeholder file only. It can be set on a placeholder directory, but it has no effect.

## See also

[CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders)