# GetNumaProcessorNodeEx function

## Description

Retrieves the node number as a **USHORT** value for the specified logical processor.

## Parameters

### `Processor` [in]

A pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure that represents the logical processor and the processor group to which it is assigned.

### `NodeNumber` [out]

A pointer to a variable to receive the node number. If the specified processor does not exist, this parameter is set to MAXUSHORT.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetNumaProcessorNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaprocessornode)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number)