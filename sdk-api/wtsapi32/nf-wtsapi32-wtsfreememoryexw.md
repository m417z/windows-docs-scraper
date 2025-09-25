# WTSFreeMemoryExW function

## Description

Frees memory that contains
[WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) or
[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures allocated by a
Remote Desktop Services function.

## Parameters

### `WTSTypeClass` [in]

A value of the [WTS_TYPE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_type_class) enumeration type
that specifies the type of structures contained in the buffer referenced by the
*pMemory* parameter.

### `pMemory` [in]

A pointer to the buffer to free.

### `NumberOfEntries` [in]

The number of elements in the buffer referenced by the *pMemory* parameter.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Several Remote Desktop Services functions allocate buffers to return information. To free buffers that
contain [WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) or
[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures, you must call the
**WTSFreeMemoryEx** function. To free other buffers,
you can call either the [WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory) function or
the **WTSFreeMemoryEx** function.

> [!NOTE]
> The wtsapi32.h header defines WTSFreeMemoryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSEnumerateProcesses](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa)

[WTSEnumerateProcessesEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesexa)

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)

[WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga)

[WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa)

[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a)