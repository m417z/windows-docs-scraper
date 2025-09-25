# WTSEnumerateProcessesExW function

## Description

Retrieves information about the active
processes on the specified Remote Desktop Session Host (RD Session Host) server or Remote Desktop Virtualization Host (RD Virtualization Host) server.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify
**WTS_CURRENT_SERVER_HANDLE** to indicate the server on which your application is
running.

### `pLevel` [in, out]

A pointer to a **DWORD** variable that, on input, specifies the type of information to return. To return an array of [WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa) structures, specify zero. To return an array of [WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) structures, specify one.

If you do not specify a valid value for this parameter, on output, **WTSEnumerateProcessesEx** sets this parameter to one and returns an error. Otherwise, on output, **WTSEnumerateProcessesEx** does not change the value of this parameter.

### `SessionId` [in]

The session for which to enumerate processes. To enumerate processes for all sessions on the server, specify **WTS_ANY_SESSION**.

### `ppProcessInfo` [out]

A pointer to a variable that receives a pointer to an array of
[WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa) or [WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) structures. The type of structure is determined by the value passed to the *pLevel* parameter. Each structure
in the array contains information about an active process. When you have finished using the array, free it by calling the [WTSFreeMemoryEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememoryexa) function. You should also set the pointer to **NULL**.

### `pCount` [out]

A pointer to a variable that receives the number of
structures returned in the buffer referenced by the *ppProcessInfo* parameter.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The caller must be a member of the Administrators group to enumerate processes that are running under another user session.

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateProcessesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)

[WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa)

[WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa)