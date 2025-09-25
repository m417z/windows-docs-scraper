# FsRtlNotifyVolumeEvent function

## Description

The **FsRtlNotifyVolumeEvent** routine notifies any registered applications that a volume event is occurring.

## Parameters

### `FileObject` [in]

A pointer to a file object for the given volume.

### `EventCode` [in]

Specifies an event code for the event that is occurring. This code can be one of the following values.

| Event Code | PnP event GUID | Meaning |
| --- | --- | --- |
| FSRTL_VOLUME_BACKGROUND_FORMAT | GUID_IO_VOLUME_BACKGROUND_FORMAT | A background format operation has been initiated. |
| FSRTL_VOLUME_CHANGE_SIZE | GUID_IO_VOLUME_CHANGE_SIZE | The size of the file system on the volume has changed. For Windows Server 2003 and Windows XP/2000, this value is not supported. |
| FSRTL_VOLUME_DISMOUNT | GUID_IO_VOLUME_DISMOUNT | The volume is being dismounted. |
| FSRTL_VOLUME_DISMOUNT_FAILED | GUID_IO_VOLUME_DISMOUNT_FAILED | The volume dismount failed. |
| FSRTL_VOLUME_FORCED_CLOSED | GUID_IO_VOLUME_FORCE_CLOSED | The volume has been made read-only by the file system. This flag is available on Windows Vista and later. |
| FSRTL_VOLUME_INFO_MAKE_COMPAT | GUID_IO_VOLUME_INFO_MAKE_COMPAT | The volume media has been removed, but it is in an incompatible state and might not be readable by a different removable-media storage device. This flag is available on Windows Vista and later. |
| FSRTL_VOLUME_LOCK | GUID_IO_VOLUME_LOCK | The volume is being locked. |
| FSRTL_VOLUME_LOCK_FAILED | GUID_IO_VOLUME_LOCK_FAILED | The volume lock failed. |
| FSRTL_VOLUME_MOUNT | GUID_IO_VOLUME_MOUNT | The volume is being mounted. |
| FSRTL_VOLUME_NEEDS_CHKDSK | GUID_IO_VOLUME_NEED_CHKDSK | Data corruption was detected on the volume and it needs to be corrected by running Chkdsk. This flag is available on Windows Vista and later. |
| FSRTL_VOLUME_PREPARING_EJECT | GUID_IO_VOLUME_PREPARING_EJECT | The file system is preparing the disc to be ejected. For Windows Server 2003 and Windows XP/2000, this value is not supported. |
| FSRTL_VOLUME_UNLOCK | GUID_IO_VOLUME_UNLOCK | The volume is being unlocked. |
| FSRTL_VOLUME_WEARING_OUT | GUID_IO_VOLUME_WEARING_OUT | The volume media is wearing out. This flag is available on Windows Vista and later. |
| FSRTL_VOLUME_WORM_NEAR_FULL | GUID_IO_VOLUME_WORM_NEAR_FULL | The volume is a write-once, read-many (WORM) volume and it is nearly full. This flag is available on Windows Vista and later. |

## Return value

**FsRtlNotifyVolumeEvent** returns the status of the notification.

## Remarks

File systems call **FsRtlNotifyVolumeEvent** to notify any registered user-mode applications that a volume event is occurring.

PnP event GUID values are defined in Ioevent.h.

To register for volume event notification, applications must call the Microsoft Win32 **RegisterDeviceNotification** function. For more information, see the Device Management section in the Microsoft Windows SDK documentation.

## See also

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[IoUnregisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotification)