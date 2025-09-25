# ILocationReport::GetSensorID

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the ID of the sensor that generated the location report.

## Parameters

### `pSensorID` [out]

Address of a **SENSOR_ID** that receives the ID of the sensor that generated the location report.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A sensor ID is a **GUID**.

#### Examples

The following example demonstrates how to call **GetSensorID**.

```cpp
    // Print the Sensor ID GUID
    GUID sensorID = {0};
    if (SUCCEEDED(spLatLongReport->GetSensorID(&sensorID)))
    {
        wprintf(L"SensorID: %s\n", GUIDToString(sensorID, szGUID, ARRAYSIZE(szGUID)));
    }

```

## See also

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport)