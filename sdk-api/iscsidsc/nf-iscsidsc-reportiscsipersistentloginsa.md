# ReportIScsiPersistentLoginsA function

## Description

The **ReportIscsiPersistentLogins** function retrieves the list of persistent login targets.

## Parameters

### `Count` [out]

A pointer to the location that receives a count of the elements specified by *PersistentLoginInfo*.

### `PersistentLoginInfo` [in, out]

An array of [PERSISTENT_ISCSI_LOGIN_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-persistent_iscsi_login_infoa) structures that, on output, describe the persistent login targets.

### `BufferSizeInBytes` [in, out]

A pointer to a location that, on input, contains the byte-size of the buffer space that *PersistentLoginInfo* specifies. If the buffer size is insufficient, this parameter specifies what is required to contain the output data.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer specified by *PersistentLoginInfo* is insufficient to contain the output data.

Otherwise, **ReportIscsiPersistentLogins** returns the appropriate Win32 or iSCSI error code on failure.

## Remarks

The [PERSISTENT_ISCSI_LOGIN_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-persistent_iscsi_login_infoa) structure provides an initiator with the information required to log in to a target each time the initiator device is started.

> [!NOTE]
> The iscsidsc.h header defines ReportIScsiPersistentLogins as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddPersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addpersistentiscsidevicea)

[ClearPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-clearpersistentiscsidevices)

[PERSISTENT_ISCSI_LOGIN_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-persistent_iscsi_login_infoa)

[RemoveIscsiPersistentTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeiscsipersistenttargeta)

[RemovePersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removepersistentiscsidevicea)

[ReportPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportpersistentiscsidevicesa)

[SetupPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-setuppersistentiscsidevices)