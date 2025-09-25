# ILatLongReport::GetAltitude

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the altitude, in meters. Altitude is relative to the reference ellipsoid.

## Parameters

### `pAltitude` [out]

Address of a **DOUBLE** that receives the altitude, in meters. May be **NULL**.

## Return value

Possible values include, but are not limited to, those in the following table.

| Return value | Description |
| --- | --- |
| S_OK | The method returned successfully. |
| HRESULT_FROM_WIN32(ERROR_NO_DATA) | The location report does not include data for the requested field. This result is returned when the location sensor does not support altitude. |

## Remarks

The **GetAltitude** method retrieves the altitude relative to the reference ellipsoid that is defined by the latest revision of the World Geodetic System (WGS 84), rather than the altitude relative to sea level.

#### Examples

The following code example demonstrates how to call **GetAltitude**. Altitude is an optional field in latitude/longitude reports, so **GetAltitude** may not always return data.

```cpp
DOUBLE altitude = 0;
// Print the Altitude
if (SUCCEEDED(spLatLongReport->GetAltitude(&altitude)))
{
    wprintf(L"Altitude: %f\n", altitude);
}
else
{
    // Altitude is optional and may not be available
    wprintf(L"Altitude: Not available.\n");
}

```

## See also

[ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport)