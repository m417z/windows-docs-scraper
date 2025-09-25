# IoVerifyVolume function

## Description

**IoVerifyVolume** sends a volume verify request to the specified removable-media device identified by the device object.

## Parameters

### `DeviceObject` [in]

Pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that identifies the device object for the device on which the volume is to be verified/mounted.

### `AllowRawMount` [in]

A value of TRUE indicates that this verify request is being issued on behalf of a DASD (direct-access storage device) open request, which indicates that a raw mount should be performed if the verify request fails.

## Return value

**IoVerifyVolume** returns the NTSTATUS code from the verify operation, which might be one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | **IoVerifyVolume** determined that the volume has not changed or was not previously mounted. |
| STATUS_INSUFFICIENT_RESOURCES | Insufficient system resources exist to complete the operation. |
| STATUS_UNSUCCESSFUL | The verify operation was unsuccessful. |
| STATUS_WRONG_VOLUME | The volume has changed. |

## Remarks

*Before using [**IoSetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetdevicetoverify) and **IoVerifyVolume**, driver writers should study the way these routines are used in the [FASTFAT sample](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/fastfat-file-system-driver).*

**IoVerifyVolume** is called to check a mounted volume on the specified device when it appears that the volume might have changed since it was last accessed. A file system driver typically calls [**IoSetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetdevicetoverify) and **IoVerifyVolume** when the lower device returns STATUS_VERIFY_REQUIRED.

If the **DeviceObject** has a mounted volume, **IoVerifyVolume** checks whether the volume has changed.

If the volume has changed or has not previously been mounted, **IoVerifyVolume** sends a volume mount request to the device.

For more information about removable-media devices, see [Supporting Removable Media](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-removable-media).

## See also

[**IoGetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdevicetoverify)

[**IoSetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetdevicetoverify)