# ILatLongReport::GetErrorRadius

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves a distance from the reported location, in meters. Combined with the location reported as the origin, this radius describes the circle in which the actual location is probably located.

## Parameters

### `pErrorRadius` [out]

Address of a **DOUBLE** that receives the error radius.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport)