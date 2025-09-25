# RtlVolumeDeviceToDosName function

## Description

The **RtlVolumeDeviceToDosName** routine is obsolete for Windows XP and later versions of Windows. Use [IoVolumeDeviceToDosName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iovolumedevicetodosname) instead.

**RtlVolumeDeviceToDosName** returns the MS-DOS path for a specified device object that represents a file system volume.

## Parameters

### `VolumeDeviceObject` [in]

Pointer to a device object that represents a volume device object created by a storage class driver.

### `DosName` [out]

Pointer to a Unicode string containing the MS-DOS path of the volume device object specified by *VolumeDeviceObject*.

## Return value

**RtlVolumeDeviceToDosName** returns STATUS_SUCCESS or an appropriate error status.

## Remarks

The behavior of this routine is identical to that of [IoVolumeDeviceToDosName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iovolumedevicetodosname). For more information about how to use this routine, see **IoVolumeDeviceToDosName**.

Drivers that must work on older NT-based operating systems may use this routine. Drivers written for Windows XP and later must use **IoVolumeDeviceToDosName** instead.