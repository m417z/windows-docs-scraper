# ILocationPermissions::GetGlobalLocationPermission

## Description

Gets the status of the system setting that allows users to change location settings.

## Parameters

### `pfEnabled` [out]

**TRUE** if system settings allow users to enable or disable the location platform; otherwise, **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for pfEnabled. |

## Remarks

**Note** **GetGlobalLocationPermission** is available in Windows 8.

For more information on location settings in Windows 8 see [Location settings](https://learn.microsoft.com/previous-versions/windows).

## See also

[ILocationPermissions](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-ilocationpermissions)