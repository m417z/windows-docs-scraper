# ReportIScsiSendTargetPortalsExW function

## Description

The **ReportIscsiSendTargetPortalsEx** function retrieves a list of static target portals that the iSCSI initiator service uses to perform automatic discovery with **SendTarget** requests.

## Parameters

### `PortalCount` [out]

A pointer to a location that, on input, contains the number of entries in the *PortalInfo* array. On output, this parameter specifies the number of elements that contain return data.

### `PortalInfoSize` [in, out]

A pointer to a location that, on input, contains the byte-size of the buffer specified by *PortalInfo*. On output, this parameter specifies the number of bytes retrieved.

### `PortalInfo` [in, out]

Pointer to an array of elements contained in a [ISCSI_TARGET_PORTAL_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_infoa) structure that describe the portals that the iSCSI initiator service utilizes to perform discovery with **SendTargets** requests.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the size of the buffer at *PortalInfo* is insufficient to contain the output data. Otherwise, **ReportIscsiSendTargetPortalsEx** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ISCSI_TARGET_PORTAL_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_infoa)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportIScsiSendTargetPortalsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).