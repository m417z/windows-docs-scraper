# RasEapInvokeConfigUI function

## Description

The RAS connection manager calls the **RasEapInvokeConfigUI** function to display a dialog to obtain configuration information from the user. RAS calls
**RasEapInvokeConfigUI** when a new phone-book entry is created or an existing phone-book entry is edited, provided that the authentication protocol for the entry provides a configuration user interface.

## Parameters

### `dwEapTypeId` [in]

Specifies the authentication protocol for which to invoke the configuration UI.

### `hwndParent` [in]

Handle to the parent window for the UI dialog.

### `dwFlags` [in]

Specifies zero or more of the following flags that qualify the authentication process.

| Flag | Meaning |
| --- | --- |
| **RAS_EAP_FLAG_ROUTER** | Specifies that the computer that is dialing in is a router. The absence of this flag indicates that the computer dialing in is a RAS client. |
| **RAS_EAP_FLAG_8021X_AUTH** | Specifies that this session is executing in a wireless context. |
| **RAS_EAP_FLAG_GUEST_ACCESS** | Specified if the client wants guest access. This flag is normally used in the case of a wireless connection such that if the authentication fails for N number of consecutive tries the wireless client, if configured to request guest access, then does so by passing this flag. The RADIUS server should be setup to permit guest access. |

### `pConnectionDataIn` [in]

Pointer to the connection data currently stored in the phone-book entry. If the phone-book entry does not contain any data, this parameter is **NULL**.

### `dwSizeOfConnectionDataIn` [in]

Specifies the size of the connection data currently stored in the phone-book entry. If the phone-book entry for this connection does not contain any data, this parameter is zero.

### `ppConnectionDataOut` [out]

Pointer to a pointer that, on successful return, points to the new connection data to store in the phone-book entry. None of this data should be specific to the current machine; phone-book entries should be portable from machine to machine.

### `pdwSizeOfConnectionDataOut` [out]

Pointer to a **DWORD** that receives the size of the new connection data to store in the phone-book entry.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function was not able to allocate memory for the configuration data, the return value should be **ERROR_NOT_ENOUGH_MEMORY**.

If the function fails in some other way, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

The DLL that implements
**RasEapInvokeConfigUI** and
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory) may support more than one authentication protocol. The *dwEapTypeId* parameter specifies for which protocol to invoke the configuration UI.

RAS stores the connection data returned by
**RasEapInvokeConfigUI** in the phone-book entry for the connection on the client computer.

## See also

[Client-Side Configuration User Interface](https://learn.microsoft.com/windows/win32/eap/client-side-configuration-user-interface)

[EAP Functions](https://learn.microsoft.com/windows/win32/eap/eap-functions)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory)

[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity)

[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui)