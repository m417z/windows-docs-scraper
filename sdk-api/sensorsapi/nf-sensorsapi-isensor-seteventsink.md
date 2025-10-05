# ISensor::SetEventSink

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Specifies the interface through which to receive sensor event notifications.

## Parameters

### `pEvents` [in]

Pointer to the [ISensorEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorevents) callback interface that receives the event notifications. Set to **NULL** to cancel event notifications.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Specify the events to receive by calling [SetEventInterest](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-seteventinterest). You can retrieve the current event interest list by calling [GetEventInterest](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-geteventinterest).

#### Examples

For an example of how to set the event sink, see [Using Sensor API Events](https://learn.microsoft.com/windows/desktop/SensorsAPI/using-sensor-api-events).

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)