# ReportPersistentIScsiDevicesA function

## Description

The **ReportPersistentIscsiDevices** function retrieves the list of persistently bound volumes and devices.

## Parameters

### `BufferSizeInChar` [in, out]

A **ULONG** value that specifies the number of list elements contained by the *Buffer* parameter.

### `Buffer` [out]

Pointer to a buffer that receives the list of volumes and devices that are persistently bound. The list consists of **null**-terminated strings. The last string, however, is double **null**-terminated.

## Return value

Returns ERROR_SUCCESS if the operation succeeds or ERROR_INSUFFICIENT_BUFFER if the buffer was insufficient to receive the output data. Otherwise, **ReportPersistentiScsiDevices** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[AddPersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addpersistentiscsidevicea)

[ClearPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-clearpersistentiscsidevices)

[RemoveIscsiPersistentTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeiscsipersistenttargeta)

[RemovePersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removepersistentiscsidevicea)

[ReportIscsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa)

[SetupPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-setuppersistentiscsidevices)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportPersistentIScsiDevices as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).