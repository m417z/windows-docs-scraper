# WTSQueryListenerConfigA function

## Description

Retrieves configuration information for a Remote Desktop Services listener.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Always set this parameter to **WTS_CURRENT_SERVER_HANDLE**.

### `pReserved` [in]

This parameter is reserved. Always set this parameter to **NULL**.

### `Reserved` [in]

This parameter is reserved. Always set this parameter to zero.

### `pListenerName` [in]

A pointer to a null-terminated string that contains the name of the listener to query.

### `pBuffer` [out]

A pointer to a [WTSLISTENERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtslistenerconfiga) structure that receives the retrieved listener configuration information.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

This function does not retrieve the security descriptor for the listener. To retrieve the security descriptor, call the [WTSGetListenerSecurity](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsgetlistenersecuritya) function.

> [!NOTE]
> The wtsapi32.h header defines WTSQueryListenerConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSGetListenerSecurity](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsgetlistenersecuritya)

[WTSLISTENERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtslistenerconfiga)