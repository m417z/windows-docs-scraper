# ISensor::SetEventInterest

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Specifies the list of sensor events to receive.

## Parameters

### `pValues` [in]

Pointer to an array of **GUID**s. Each **GUID** represents an event to receive. Set to **NULL** to receive all data-updated events and all custom events.

### `count` [in]

The count of **GUID**s in the array pointed to by *pValues*. Set to zero when *pValues* is **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Each sensor event is represented by a **GUID**. This method takes, as an array of **GUID**s, the list of events that you want to receive.

#### Examples

For an example of how to set event interest, see [Using Sensor API Events](https://learn.microsoft.com/windows/desktop/SensorsAPI/using-sensor-api-events).

## See also

[GetEventInterest](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-geteventinterest)

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)