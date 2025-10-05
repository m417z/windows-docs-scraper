# ISensorEvents::OnEvent

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Provides custom event notifications.

## Parameters

### `pSensor` [in]

Pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface that represents the sensor that raised the event.

### `eventID` [in]

**REFGUID** that identifies the event.

### `pEventData` [in]

Pointer to the [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) interface that contains the event data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This callback method receives custom event notifications. Custom events are defined by sensor providers. Platform-defined event IDs are defined in Sensors.h.

To receive new data from a sensor, use the [OnDataUpdated Method](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensorevents-ondataupdated).

#### Examples

For an example of how to receive sensor events, see [Using Sensor API Events](https://learn.microsoft.com/windows/desktop/SensorsAPI/using-sensor-api-events).

## See also

[ISensorEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorevents)