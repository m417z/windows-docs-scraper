# WTSCreateListenerA function

## Description

Creates a new Remote Desktop Services listener or configures an existing listener.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Always set this parameter to **WTS_CURRENT_SERVER_HANDLE**.

### `pReserved` [in]

This parameter is reserved. Always set this parameter to **NULL**.

### `Reserved` [in]

This parameter is reserved. Always set this parameter to zero.

### `pListenerName` [in]

A pointer to a null-terminated string that contains the name of the listener to create or configure.

### `pBuffer` [in]

A pointer to a [WTSLISTENERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtslistenerconfiga) structure that contains configuration information for the listener.

### `flag` [in]

The purpose of the call. This parameter can be one of the following values.

#### WTS_LISTENER_CREATE (1 (0x1))

Create a new listener.

#### WTS_LISTENER_UPDATE (16 (0x10))

Update the settings of an existing listener.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

This function creates or configures a listener that uses [Remote Desktop Protocol](https://learn.microsoft.com/windows/desktop/TermServ/remote-desktop-protocol) (RDP). Always set the **version** member of the [WTSLISTENERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtslistenerconfiga) structure that is pointed to by the *pBuffer* parameter to one.

This function does not create or configure the security descriptor of the listener. When you call this function to create a new listener, the function assigns the default security descriptor to the new listener. To modify the security descriptor, call the [WTSSetListenerSecurity](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetlistenersecuritya) function. For more information about security descriptors, see [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor).

This function does not validate the settings for the new listener. Be sure that the settings are valid before calling this function.

> [!NOTE]
> The wtsapi32.h header defines WTSCreateListener as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[WTSLISTENERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtslistenerconfiga)

[WTSSetListenerSecurity](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetlistenersecuritya)