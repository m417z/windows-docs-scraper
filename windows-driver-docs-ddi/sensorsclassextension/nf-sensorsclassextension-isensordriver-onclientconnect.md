# ISensorDriver::OnClientConnect

## Description

The [ISensorDriver::OnClientConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientconnect) method notifies the sensor driver that a client application has connected.

## Parameters

### `pClientFile`

Pointer to an IWDFFile interface that represents the file object for the application requesting the connection.

### `pwszSensorID`

LPWSTR that contains the ID for the sensor to which the client application is connecting.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The sensor class extension calls this method only if the specified client application has been given permission by the user to access the driver. If the user revokes this permission, the class extension immediately calls [ISensorDriver::OnClientDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientdisconnect) for the same application/sensor pair.

The class extension always calls this method before calling [ISensorDriver::OnSetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onsetproperties) or [ISensorDriver::OnGetDataFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetdatafields) for a particular sensor. We recommend that you maintain a reference count of connected applications to help to anticipate when calls to these three methods are possible. If no client applications are connected, you may want to change the behavior of the driver, for example, by taking steps to reduce power consumption.

You can use the pointer value (the address pointed to) provided by *pClientFile* as a kind of ID to keep track of connected applications. However, you must track these IDs separately for each sensor, not for each device, because the class extension may provide the same pointer value to multiple sensors on the same device.

For more information about how to use this method, see [Filtering data](https://learn.microsoft.com/windows-hardware/drivers/sensors/filtering-data).

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)