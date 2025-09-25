# ISensorDriver::OnClientUnsubscribeFromEvents

## Description

The [ISensorDriver::OnClientUnsubscribeFromEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientunsubscribefromevents) method notifies the sensor driver that a client application no longer requests event notifications.

## Parameters

### `pClientFile`

 Pointer to an IWDFFile interface that represents the file object for the application requesting cancellation of event notifications.

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting cancellation of event notifications.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The sensor class extension calls this method in the following instances:

* An application unsubscribes from events.
* An application closes normally.
* The user revokes permission for an application to access the device that contains the specified sensor.
* The sensor class extension is shutting down.
* The cleanup work from a call to [ISensorClassExtension::CleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-cleanupfile) has completed.

You can use this call as a signal to update the reference count of applications requesting events for the specified sensor.

For more information about how to use this method, see [Filtering data](https://learn.microsoft.com/windows-hardware/drivers/sensors/filtering-data).

The ClientData structure is defined as follows.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)