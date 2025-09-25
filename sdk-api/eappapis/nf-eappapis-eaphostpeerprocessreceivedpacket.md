# EapHostPeerProcessReceivedPacket function

## Description

Is called by the supplicant every time the supplicant receives a packet that EAPHost
needs to process. **EapHostPeerProcessReceivedPacket** should be called only after a successful call to
[EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession). *sessionHandle* can be zero if the supplicant receives a new identity request not associated with any session.

### `cbReceivePacket` [in]

 The size, in bytes, of the received packet buffer pointed to by the *cbReceivePacket* parameter.

### `pReceivePacket` [in]

A pointer to a buffer that contains the incoming EAP data received by
the supplicant.

### `pEapOutput` [out]

A pointer to an [EapHostPeerResponseAction](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) value that indicates the supplicant should take appropriate action. Typically the supplicant either calls
another method on EAPHost or acts on its own.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)