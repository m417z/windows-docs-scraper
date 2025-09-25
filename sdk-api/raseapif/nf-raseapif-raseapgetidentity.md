# RasEapGetIdentity function

## Description

The RAS connection manager calls the
**RasEapGetIdentity** function to obtain identity information for the user requesting authentication.

## Parameters

### `dwEapTypeId` [in]

Specifies the authentication protocol for which to invoke the identity user interface.

### `hwndParent` [in]

Handle to the parent window for the user interface dialog. If the *dwFlags* parameter contains the RAS_EAP_FLAG_NON_INTERACTIVE flag, then *hwndParent* is **NULL**.

### `dwFlags` [in]

Specifies zero or more of the following flags that qualify the authentication process.

| Flag | Meaning |
| --- | --- |
| **RAS_EAP_FLAG_ROUTER** | Specifies that the computer that is dialing in is a router. The absence of this flag indicates that the computer dialing in is a RAS client. |
| **RAS_EAP_FLAG_NON_INTERACTIVE** | Specifies that the authentication protocol should not bring up a user-interface. If the authentication protocol is not able to determine the identity from the data supplied, it should return the error code, **ERROR_INTERACTIVE_MODE**. If this flag is specified, the *hwndParent* parameter will be **NULL**. |
| **RAS_EAP_FLAG_LOGON** | Specifies that the user data is obtained when logging onto the local system, that is from Winlogon.exe. |
| **RAS_EAP_FLAG_PREVIEW** | Specifies that the user should be prompted for identity information before dialing. |
| **RAS_EAP_FLAG_FIRST_LINK** | Indicates that this connection is the first link in a multilink connection. See [Multilink and Callback Connections](https://learn.microsoft.com/windows/win32/eap/multilink-and-callback-connections) for more information. |
| **RAS_EAP_FLAG_MACHINE_AUTH** | Specifies that the authentication process use machine credentials for authentication. The credentials can be a certificate, machine name/password as in the case of MSCHAPv2 or any other means of identifying the machine. If the authentication protocol does not support machine authentication, it should return the error **ERROR_NOT_SUPPORTED**. |
| **RAS_EAP_FLAG_8021X_AUTH** | Specifies that this session is executing in a wireless context. |

### `pwszPhonebook` [in]

Pointer to a null-terminated Unicode string that specifies the full path of the phone-book (PBK) file. If this parameter is **NULL**, the function uses the system phone book.

### `pwszEntry` [in]

Pointer to a null-terminated Unicode string that specifies an existing entry name.

### `pConnectionDataIn` [in]

Pointer to the connection-specific data currently stored in the phone-book entry.

### `dwSizeOfConnectionDataIn` [in]

Specifies the size of the connection-specific data currently stored in the phone-book entry.

### `pUserDataIn` [in]

Pointer to the user-specific data currently stored for this user in the registry.

### `dwSizeOfUserDataIn` [in]

Specifies the size of the user-specific data currently stored for this user in the registry.

### `ppUserDataOut` [out]

Pointer to a pointer that, on successful return, points to the identity data for the user. This data will be passed to the authentication protocol in the **pUserData** member of
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) during the call to
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)).

The authentication protocol should allocate the memory buffer for the identity data. RAS will free this memory by calling
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory).

### `pdwSizeOfUserDataOut` [out]

Pointer to a **DWORD** variable that receives the size of the data pointed to by the *ppUserDataOut* parameter.

### `ppwszIdentityOut` [out]

Pointer to a pointer that, on successful return, points to a null-terminated Unicode string that identifies the user requesting authentication. This string is passed to the authentication protocol in the **pszIdentity** member of
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) during the call to
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function was not able to allocate memory for the user data, the return value should be **ERROR_NOT_ENOUGH_MEMORY**.

If the function is called with the RAS_EAP_FLAG_NON_INTERACTIVE flag, but must invoke a user interface to determine the user's identity, the function should return **ERROR_INTERACTIVE_MODE**.

If the function fails in some other way, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

The DLL that implements
**RasEapGetIdentity** and
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory) may support more than one authentication protocol. The *dwEapTypeId* parameter specifies for which protocol to invoke the identity user interface.

The IEEE 802.1X and PPP protocols do not call
**RasEapGetIdentity** without an implementation of
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory).

The authentication protocol receives the data returned from
**RasEapGetIdentity** in the **pUserData** member of
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) during
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)). To store the data for this user in the registry, the authentication protocol should set the **pUserData** member of
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) to point to the data, and the **fSaveUserData** member of
**PPP_EAP_OUTPUT** to **TRUE**.

This function is called by the RAS function,
[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya).

If
**RasEapGetIdentity** displays a user interface, the user interface must support
[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages where
[LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85))(*wParam*) equals IDCANCEL.

## See also

[EAP Functions](https://learn.microsoft.com/windows/win32/eap/eap-functions)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[Obtaining Identity Information](https://learn.microsoft.com/windows/win32/eap/obtaining-identity-information)

[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input)

[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))

[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya)