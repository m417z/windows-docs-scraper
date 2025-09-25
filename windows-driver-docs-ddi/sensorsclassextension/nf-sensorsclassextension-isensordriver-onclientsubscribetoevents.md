# ISensorDriver::OnClientSubscribeToEvents

## Description

The [ISensorDriver::OnClientSubscribeToEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientsubscribetoevents) method notifies the sensor driver that an authorized client application is requesting event notifications.

## Parameters

### `pClientFile`

Pointer to an IWDFFile interface that represents the file object for the application requesting event notifications.

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting event notifications.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

When a client application requests event notifications, the driver raises all events to the sensor class extension for the specified object ID. The class extension then forwards these events to the Sensor API as event notifications for applications.

You can maintain a reference count of connected applications for each sensor to avoid making event callbacks when not required.

Platform-defined events are defined in sensors.h.

For more information about how to use this method, see [Filtering data](https://learn.microsoft.com/windows-hardware/drivers/sensors/filtering-data).

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)