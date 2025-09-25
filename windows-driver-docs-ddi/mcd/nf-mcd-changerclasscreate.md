# ChangerClassCreate function

## Description

The **ChangerClassCreate** routine is called by a changer minidriver to allow the class driver perform device-independent operations needed to create or close a device.

## Parameters

### `DeviceObject` [in]

Pointer to the device object of the device to be created or closed.

### `Irp` [in]

Pointer to the I/O request packet (IRP) that initiated the create or close operation.

## Return value

If the operation succeeds, the **ChangerClassCreate** routine returns STATUS_SUCCESS. Otherwise the routine returns one of the following status values.

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_DEVICE** | The device object does not have a properly initialized device extension. |
| **STATUS_DEVICE_BUSY** | The device is already open. Only one open at a time is allowed. |