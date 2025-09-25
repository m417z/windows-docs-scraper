# ILatLongReport::GetAltitudeError

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation)
API.
]

Retrieves the altitude error, in meters.

## Parameters

### `pAltitudeError` [out]

Address of a **DOUBLE** that receives the altitude error, in meters. May be **NULL**.

## Return value

Possible values include, but are not limited to, those in the following table.

| Return value | Description |
| --- | --- |
| S_OK | The method returned successfully. |
| HRESULT_FROM_WIN32(ERROR_NO_DATA) | The location report does not include data for the requested field. This result is returned when the location sensor does not support altitude. |

## See also

[ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport)