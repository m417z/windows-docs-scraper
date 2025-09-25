# WTSEnumerateSessionsExA function

## Description

Retrieves a list of sessions on a specified Remote Desktop Session Host (RD Session Host) server or Remote Desktop Virtualization Host (RD Virtualization Host) server.

## Parameters

### `hServer` [in]

A handle to the target server. Specify a handle returned by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function. To enumerate sessions on the RD Session Host server on which the application is running, specify **WTS_CURRENT_SERVER_HANDLE**.

### `pLevel` [in, out]

This parameter is reserved. Always set this parameter to one. On output, **WTSEnumerateSessionsEx** does not change the value of this parameter.

### `Filter` [in]

This parameter is reserved. Always set this parameter to zero.

### `ppSessionInfo` [out]

A pointer to a **PWTS_SESSION_INFO_1** variable that receives a pointer to an array of
[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures. Each structure in the array contains information about a session on the specified RD Session Host server. If you obtained a handle to an RD Virtualization Host server by calling the [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function, the array contains information about sessions on virtual machines on the server. When you have finished using the array, free it by calling the [WTSFreeMemoryEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememoryexa) function. You should also set the pointer to **NULL**.

### `pCount` [out]

A pointer to a **DWORD** variable that receives the number of
[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures returned in the *ppSessionInfo* buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

To obtain information about sessions running on virtual machines on an RD Virtualization Host server, you must obtain the handle by calling the [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function. To free the returned buffer, call the
[WTSFreeMemoryEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememoryexa) function and set the *WTSClassType* parameter to **WTSTypeSessionInfoLevel1**.

To enumerate a session, you need to have the Query Information permission for that session. For more information, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative tool.

To enumerate sessions running on a virtual machine hosted on an RD Virtualization Host server, you must be a member of the Administrators group on the RD Virtualization Host server.

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateSessionsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSFreeMemoryEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememoryexa)

[WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa)

[WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a)