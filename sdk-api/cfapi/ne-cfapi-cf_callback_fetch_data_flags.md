# CF_CALLBACK_FETCH_DATA_FLAGS enumeration

## Description

Callback flags for fetching data for a placeholder file or folder.

## Constants

### `CF_CALLBACK_FETCH_DATA_FLAG_NONE:0x00000000`

No data fetch flag.

### `CF_CALLBACK_FETCH_DATA_FLAG_RECOVERY:0x00000001`

Flag to be used if the callback is invoked as a result of previously interrupted hydration process, due to either unexpected shutdown of the sync provider or power loss, etc.

### `CF_CALLBACK_FETCH_DATA_FLAG_EXPLICIT_HYDRATION:0x00000002`

>[!NOTE]
>This value is new for Windows 10, version 1803.

Flag to be used if the callback is invoked as a result of a call to [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder).

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)

[CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder)