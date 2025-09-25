# CF_CONNECT_FLAGS enumeration

## Description

Additional information that can be requested by a sync provider when its callbacks are invoked.

## Constants

### `CF_CONNECT_FLAG_NONE:0x00000000`

No connection flags.

### `CF_CONNECT_FLAG_REQUIRE_PROCESS_INFO:0x00000002`

When this flag is specified, the platform returns the full image path of the hydrating process in the callback parameters.

### `CF_CONNECT_FLAG_REQUIRE_FULL_FILE_PATH:0x00000004`

When this flag is specified, the platform returns the full path of the placeholder being requested in the callback parameters.

### `CF_CONNECT_FLAG_BLOCK_SELF_IMPLICIT_HYDRATION:0x00000008`

>[!NOTE]
>This value is new for Windows 10, version 1803.

When this flag is specified, The implicit hydration, which is not performed via [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder), can happen when the anti-virus software scans a sync provider’s file system activities on non-hydrated cloud file placeholders. This kind of implicit hydration is not expected. If the sync provider never initiates implicit hydration operations, it can instruct the platform to block all such implicit hydration operations, as opposed to failing the **FETCH_DATA** callbacks later.

## See also

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)

[CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder)