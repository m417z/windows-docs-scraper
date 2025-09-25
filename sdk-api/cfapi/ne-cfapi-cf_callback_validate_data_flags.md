# CF_CALLBACK_VALIDATE_DATA_FLAGS enumeration

## Description

Flags to validate the data of a placeholder file or directory.

## Constants

### `CF_CALLBACK_VALIDATE_DATA_FLAG_NONE:0x00000000`

No data validation flag.

### `CF_CALLBACK_VALIDATE_DATA_FLAG_EXPLICIT_HYDRATION:0x00000002`

>[!NOTE]
>This value is new for Windows 10, version 1803.

Set if the callback is invoked as a result of a call to [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder).

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)

[CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder)