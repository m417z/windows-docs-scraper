# ILatLongReport::GetLongitude

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the longitude, in degrees. The longitude is between -180 and 180, where East is positive.

## Parameters

### `pLongitude` [out]

Address of a **DOUBLE** that receives the longitude.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport)