# IoSetDeviceToVerify function

## Description

The **IoSetDeviceToVerify** routine sets the device object to be verified in the specified thread. The specified device object represents a removable media device.

## Parameters

### `Thread` [in]

Pointer to an [**ETHREAD**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) thread object structure for the thread.

### `DeviceObject` [in, optional]

Pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that identifies the device object for a removable-media device. **DeviceObject** can be NULL.

## Remarks

*Before using **IoSetDeviceToVerify** and [**IoVerifyVolume**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioverifyvolume), driver writers should study the way these routines are used in the FASTFAT sample. For additional information, see also [Supporting Removable Media](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-removable-media).*

**IoSetDeviceToVerify** is called to indicate that a given device object, representing a removable-media device, needs to be verified. Call [**IoGetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdevicetoverify) to obtain the device object that is the target of the given thread's I/O request.

A file system driver must verify a volume when it receives notification from an underlying removable-media device driver that the media appears to have changed since the last access to the target device. The file system typically calls **IoSetDeviceToVerify** and [**IoVerifyVolume**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioverifyvolume) when the lower device returns STATUS_VERIFY_REQUIRED.

## See also

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[**IoGetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdevicetoverify)

[**IoVerifyVolume**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioverifyvolume)

[**PsGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)