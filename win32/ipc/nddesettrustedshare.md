# NDdeSetTrustedShare function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Grants the specified DDE share trusted status within the current user's context.

## Parameters

*lpszServer* \[in\]

The name of the server whose DSDM is to be modified.

*lpszShareName* \[in\]

The name of the share to be granted trusted status. This parameter cannot be **NULL**.

*dwTrustOptions* \[in\]

The options affecting the trusted status of the DDE share. This parameter can be one of the following values.

| Option | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| **NDDE\_CMD\_SHOW\_MASK**<br>0x0000FFFFL | Mask used to obtain the value used to override the DDE share show state, if NDDE\_TRUST\_CMD\_SHOW is set.<br> |
| **NDDE\_TRUST\_CMD\_SHOW**<br>0x10000000L | Override the show state specified in the DDE share DSDM.<br> |
| **NDDE\_TRUST\_SHARE\_DEL**<br>0x20000000L | Remove the share's trusted status.<br> |
| **NDDE\_TRUST\_SHARE\_INIT**<br>0x40000000L | Allow a client to initiate to the application if it is already running in the user's context.<br> |
| **NDDE\_TRUST\_SHARE\_START**<br>0x80000000L | Allow the application to be started in the user's context.<br> |

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Remarks

The DDE share must first be created with [**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd).

If **NDdeSetTrustedShare** is called with *dwTrustOptions* set to zero, the trusted share loses its trusted status.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeSetTrustedShareW** (Unicode) and **NDdeSetTrustedShareA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd)

