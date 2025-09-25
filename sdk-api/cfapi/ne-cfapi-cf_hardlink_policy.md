## Description

Specifies whether or not hard links are allowed on placeholder files.

## Constants

### `CF_HARDLINK_POLICY_NONE:0x00000000`

Default; No hard links can be created on any placeholder.

### `CF_HARDLINK_POLICY_ALLOWED:0x00000001`

Hard links can be created on a placeholder under the same sync root or no sync root.

## Remarks

If hard links are enabled, applications can create as many hard links as the file system supports so long as the links are under the same sync root or no sync root. Hard links and placeholder operations that are not compatible with this policy will fail with the error: **HRESULT(ERROR_CLOUD_FILES_INCOMPATIBLE_HARDLINKS)**.

## See also

[CF_SYNC_POLICIES](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_policies)