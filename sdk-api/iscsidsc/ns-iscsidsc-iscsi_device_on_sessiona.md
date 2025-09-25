# ISCSI_DEVICE_ON_SESSIONA structure

## Description

The **ISCSI_DEVICE_ON_SESSION** structure specifies multiple methods for identifying a device associated with an iSCSI login session.

## Members

### `InitiatorName`

A string that indicates the initiator name.

### `TargetName`

A string that indicates the target name.

### `ScsiAddress`

A SCSI_ADDRESS structure that contains the SCSI address of the device.

### `DeviceInterfaceType`

A GUID that specifies the device interface class associated with the device. Device interface class GUIDs include, but are not limited to, the following:

| GUID | Type of Device |
| --- | --- |
| GUID_DEVINTERFACE_DISK | Disk |
| GUID_DEVINTERFACE_TAPE | Tape |
| GUID_DEVINTERFACE_CDROM | CD-ROM |
| GUID_DEVINTERFACE_WRITEONCEDISK | Write Once Disk |
| GUID_DEVINTERFACE_CDCHANGER | CD Changer |
| GUID_DEVINTERFACE_MEDIUMCHANGER | Medium Changer |
| GUID_DEVINTERFACE_FLOPPY | Floppy |

### `DeviceInterfaceName`

A string that specifies the name of the device interface class.

### `LegacyName`

A string that specifies the legacy device name.

### `StorageDeviceNumber`

A **STORAGE_DEVICE_NUMBER** structure containing the storage device number.

### `DeviceInstance`

A handle to the instance of the device in the devnode tree. For information on the cfgmgr32Xxx functions that utilize this handle, see PnP Configuration Manager Functions.

## See also

**SCSI_ADDRESS**

**STORAGE_DEVICE_NUMBER**

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_DEVICE_ON_SESSION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).