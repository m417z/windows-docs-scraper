# _FLT_VOLUME_PROPERTIES structure

## Description

The FLT_VOLUME_PROPERTIES structure is passed as a parameter to [FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties).

## Members

### `DeviceType`

Receives the device type of the volume. Must be a valid storage device type, such as one of the following values defined in ntifs.h:

FILE_DEVICE_CD_ROM

FILE_DEVICE_DISK

FILE_DEVICE_DVD

FILE_DEVICE_MASS_STORAGE

FILE_DEVICE_NETWORK

FILE_DEVICE_VIRTUAL_DISK

For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `DeviceCharacteristics`

Receives the device characteristics of the volume. For more information, see the reference entry for [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice).

### `DeviceObjectFlags`

Receives the device object flags for the volume. For more information about these flags, see the reference entries for [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) and [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `AlignmentRequirement`

Receives the buffer alignment required by the underlying device. The value must be one of the FILE_*xxxx*_ALIGNMENT values defined in ntifs.h. For more information, see [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) and [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object).

### `SectorSize`

Receives the volume sector size, in bytes.

### `Flags`

Provides additional description of the volume. This member can be zero or one of the following flags. In versions prior to Windows 10, version 1607, this member was named **Reserved0** and reserved for system use.

| Value | Meaning |
| --- | --- |
| **VOL_PROP_FL_DAX_VOLUME** | This flag indicates that the volume is a direct access (DAX) volume. |

### `FileSystemDriverName`

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that receives the service name of the file system that is mounted on this volume. The buffer for this Unicode string is contiguous with this structure and does not need to be initialized before calling [FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties).

### `FileSystemDeviceName`

UNICODE_STRING structure that receives the name of the file system device object associated with this volume. The buffer for this Unicode string is contiguous with this structure and does not need to be initialized before calling [FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties).

### `RealDeviceName`

UNICODE_STRING structure that receives the name of the storage device object associated with this volume. This structure is empty for network file systems. The buffer for this Unicode string is contiguous with this structure and does not need to be initialized before calling [FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties).

## Remarks

Storage for the FLT_VOLUME_PROPERTIES structure is typically allocated from paged pool.

To get the volume name for a given volume, call [FltGetVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename).

To get the volume globally unique identifier (GUID) name for a given volume, call [FltGetVolumeGuidName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

**FltGetVolumeName**

[FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)