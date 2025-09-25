# WTSEnumerateProcessesA function

## Description

Retrieves information about the active
processes on a specified Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `hServer` [in]

Handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify
**WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application is
running.

### `Reserved` [in]

Reserved; must be zero.

### `Version` [in]

Specifies the version of the enumeration request. Must be 1.

### `ppProcessInfo` [out]

Pointer to a variable that receives a pointer to an array of
[WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa) structures. Each structure
in the array contains information about an active process on the specified RD Session Host server. To free the returned
buffer, call the [WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory) function.

### `pCount` [out]

Pointer to a variable that receives the number of **WTS_PROCESS_INFO**
structures returned in the *ppProcessInfo* buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller must be a member of the Administrators group to enumerate processes that are running under a
different user's context.

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateProcesses as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa)