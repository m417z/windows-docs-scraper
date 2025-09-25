# EapHostPeerGetAuthStatus function

## Description

Obtains the supplicant's current EAP authentication status from EAPHost.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `authParam` [in]

An [EapHostPeerAuthParams](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerauthparams) enumeration value that specifies the type of EAP authentication data to obtain from EAPHost.

| Value | Meaning |
| --- | --- |
| **EapHostPeerAuthStatus** | *ppAuthData* contains a [EAPHOST_AUTH_INFO](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ns-eaphostpeertypes-eaphost_auth_info) structure. |
| **EapHostPeerIdentity** | *ppAuthData* contains a **WCHAR** buffer. |
| **EapHostPeerIdentityExtendedInfo** | *ppAuthData* contains a **CHAR** buffer. |
| **EapHostNapInfo** | Windows 7 or later: [EapHostPeerNapInfo](https://learn.microsoft.com/windows/win32/eaphost/eaphostpeernapinfo) structure. |

### `pcbAuthData` [out]

The size, in bytes, of the EAP authentication data buffer pointed to by the *ppAuthData* parameter.

### `ppAuthData` [out]

A pointer to a pointer to a byte buffer that contains the authentication data from EAPHost. The format of this data depends on the value supplied in *authParam*.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)