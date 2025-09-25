# ReportIScsiTargetsA function

## Description

The **ReportIscsiTargets** function retrieves the list of targets that the iSCSI initiator service has discovered, and can also instruct the iSCSI initiator service to refresh the list.

## Parameters

### `ForceUpdate` [in]

If **true**, the iSCSI initiator service updates the list of discovered targets before returning the target list data to the caller.

### `BufferSize` [in, out]

A **ULONG** value that specifies the number of list elements contained by the *Buffer* parameter.

### `Buffer` [out]

Pointer to a buffer that receives and contains the list of targets. The list consists of **null**-terminated strings. The last string, however, is double **null**-terminated.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer size is insufficient to contain the output data. Otherwise, **ReportIscsiTargets** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ReportIscsiSendTargetPortals](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsisendtargetportalsa)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportIScsiTargets as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).