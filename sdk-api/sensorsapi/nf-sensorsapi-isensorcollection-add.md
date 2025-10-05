# ISensorCollection::Add

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Adds a sensor to the collection.

## Parameters

### `pSensor` [in]

Pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface for the sensor to add to the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The sensor collection already contains a sensor with the specified ID. |

## See also

[ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection)