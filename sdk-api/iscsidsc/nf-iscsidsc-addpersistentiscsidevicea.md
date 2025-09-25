# AddPersistentIScsiDeviceA function

## Description

The **AddPersistentIscsiDevice** function adds a volume device name, drive letter, or mount point symbolic link to the list of iSCSI persistently bound volumes and devices.

## Parameters

### `DevicePath` [in]

A drive letter or symbolic link for a mount point of the volume.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns one of the following:

| Return code | Description |
| --- | --- |
| **ISDSC_DEVICE_NOT_ISCSI_OR_PERSISTENT** | The volume or device is not located on a iSCSI target or the session to the iSCSI target is not persistent. |
| **ISDSC_VOLUME_ALREADY_PERSISTENTLY_BOUND** | The volume or device is already in the persistent volume or device list. |

## See also

[ClearPersistentScsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-clearpersistentiscsidevices)

[RemoveIscsiPersistentTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeiscsipersistenttargeta)

[RemovePersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removepersistentiscsidevicea)

[ReportIscsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa)

[ReportPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportpersistentiscsidevicesa)

[SetupPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-setuppersistentiscsidevices)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines AddPersistentIScsiDevice as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).