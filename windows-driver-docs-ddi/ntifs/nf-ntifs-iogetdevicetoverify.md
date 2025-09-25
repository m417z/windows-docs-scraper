# IoGetDeviceToVerify function

## Description

The **IoGetDeviceToVerify** routine returns a pointer to the device object, representing a removable-media device, that is the target of the given thread's I/O request.

## Parameters

### `Thread` [in]

Pointer to an [**ETHREAD**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure whose device object is being queried. That is, **Thread** is the thread for which a highest-level driver is attempting to verify the validity of the media on which the thread has opened a file.

## Return value

**IoGetDeviceToVerify** returns a pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that identifies the device object representing a device on which the media should be verified. This function can return NULL.

## Remarks

In general, highest-level drivers, particularly file systems, are most likely to call this routine.

An underlying removable-media device driver is responsible for notifying higher-level drivers, particularly the file system, when the media appears to have changed since the last access to the target device. For more information, see [Notifying the File System of Possible Media Changes](https://learn.microsoft.com/windows-hardware/drivers/kernel/notifying-the-file-system-of-possible-media-changes).

## See also

[**IoIsErrorUserInduced**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiserroruserinduced)

[**IoSetDeviceToVerify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetdevicetoverify)

[**IoSetHardErrorOrVerifyDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice)

[**PsGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)