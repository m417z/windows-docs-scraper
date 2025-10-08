# NDdeGetTrustedShare function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Retrieves the options associated with a DDE share that is in the server user's list of trusted shares.

## Parameters

*lpszServer* \[in\]

The name of the server on which the DSDM resides.

*lpszShareName* \[in\]

The share name whose trusted status is being queried. This parameter cannot be **NULL**.

*lpdwTrustOptions* \[out\]

A pointer to a variable that receives the trust options. This parameter cannot be **NULL**. The following trust options are available.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| **NDDE\_CMD\_SHOW\_MASK**<br>0x0000FFFFL | Mask used to obtain the value used to override the DDE share show state, if NDDE\_TRUST\_CMD\_SHOW is set.<br> |
| **NDDE\_TRUST\_CMD\_SHOW**<br>0x10000000L | Override the show state specified in the DDE share DSDM.<br> |
| **NDDE\_TRUST\_SHARE\_DEL**<br>0x20000000L | Remove the share's trusted status.<br> |
| **NDDE\_TRUST\_SHARE\_INIT**<br>0x40000000L | Allow a client to initiate to the application if it is already running in the user's context.<br> |
| **NDDE\_TRUST\_SHARE\_START**<br>0x80000000L | Allow the application to be started in the user's context.<br> |

*lpdwShareModId0* \[out\]

A pointer to a variable that receives the first part of the trusted share modify identifier. This parameter cannot be **NULL**.

*lpdwShareModId1* \[out\]

A pointer to a variable that receives the second part of the trusted share modify identifier. This parameter cannot be **NULL**.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Remarks

The trusted share modify identifier reflects the version of the DDE share in the DSDM at the time the DDE share was initially granted trusted status. The trusted share modify identifier is primarily used to remove obsolete trusted shares. However, the user does not need to remove obsolete trusted shares. The network DDE agent removes obsolete shares on the user's behalf.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeGetTrustedShareW** (Unicode) and **NDdeGetTrustedShareA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDdeSetTrustedShare**](https://learn.microsoft.com/windows/win32/ipc/nddesettrustedshare)

