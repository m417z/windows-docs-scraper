# ReportIScsiInitiatorListW function

## Description

The **ReportIscsiInitiatorList** function retrieves the list of initiator Host Bus Adapters that are running on the machine.

## Parameters

### `BufferSize` [in, out]

A **ULONG** value that specifies the number of list elements contained by the *Buffer* parameter.
If the operation succeeds, this location receives the size, represented by a number of elements, that corresponds to the retreived data.

### `Buffer` [out]

A buffer that, on output, is filled with the list of initiator names. Each initiator name is a **null**-terminated string, except for the last initiator name, which is double-**null** terminated.

## Return value

 Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer size of Buffer is insufficient to contain the output data.

 Otherwise, **ReportIscsiInitiatorList** returns the appropriate Win32 or iSCSI error code on failure.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportIScsiInitiatorList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).