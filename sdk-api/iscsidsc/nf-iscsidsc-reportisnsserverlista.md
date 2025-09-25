# ReportISNSServerListA function

## Description

The **ReportIsnsServerList** function retrieves the list of Internet Storage Name Service (iSNS) servers that the iSCSI initiator service queries for discovered targets.

## Parameters

### `BufferSizeInChar` [in, out]

A **ULONG** value that specifies the number of list elements contained by the *Buffer* parameter.
If the operation succeeds, this location receives the size, represented by a number of elements, that corresponds to the number of retrieved iSNS servers.

### `Buffer` [out]

The buffer that holds the list of iSNS servers on output. Each server name is **null** terminated, except for the last server name, which is double **null** terminated.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer is too small to hold the output data.

Otherwise, **ReportIsnsServerList** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[AddIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addisnsservera)

[RefreshIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-refreshisnsservera)

[RemoveIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeisnsservera)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportISNSServerList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).