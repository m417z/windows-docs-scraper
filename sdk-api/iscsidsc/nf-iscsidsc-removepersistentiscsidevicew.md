# RemovePersistentIScsiDeviceW function

## Description

The **RemovePersistentIscsiDevice** function removes a device or volume from the list of persistently bound iSCSI volumes.

## Parameters

### `DevicePath` [in]

A drive letter, mount point, or device path for the volume or device.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ISDSC_DEVICE_NOT_FOUND if the volume that is specified by *VolumePath* is not in the list of persistently bound volumes.

Otherwise, **RemovePersistentIscsiDevice** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[AddPersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addpersistentiscsidevicea)

[ClearPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-clearpersistentiscsidevices)

[RemoveIscsiPersistentTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeiscsipersistenttargeta)

[ReportIscsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa)

[ReportPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportpersistentiscsidevicesa)

[SetupPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-setuppersistentiscsidevices)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RemovePersistentIScsiDevice as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).