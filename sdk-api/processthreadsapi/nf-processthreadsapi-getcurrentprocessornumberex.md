# GetCurrentProcessorNumberEx function

## Description

Retrieves the processor group and number of the logical processor in which the calling thread is running.

## Parameters

### `ProcNumber` [out]

A pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure that receives the processor group to which the logical processor is assigned and the number of the logical processor within its group.

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).