# ChangerClassDeviceControl function

## Description

The **ChangerClassDeviceControl** routine is called by a changer minidriver to allow the class driver perform device-independent aspects of a device control operation.

## Parameters

### `DeviceObject` [in]

Pointer to the device object of the device.

### `Irp` [in]

Pointer to the I/O request packet (IRP) that initiated the device control operation.

## Return value

If the operation succeeds, the **ChangerClassDeviceControl** routine returns STATUS_SUCCESS. Otherwise the routine returns one of the following status values.

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_DEVICE** | The device object does not have a properly initialized device extension. |
| **STATUS_INFO_LENGTH_MISMATCH** | The length of the output buffer indicated in the IRP is too small to hold the return data. |
| **STATUS_BUFFER_TOO_SMALL** | The length of the input buffer indicated in the IRP is too small to hold the input data that is necessary to complete the operation. |
| **STATUS_INVALID_PARAMETER** | The length of the input buffer is zero. |