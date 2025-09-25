# EapHostPeerGetSendPacket function

## Description

Is called by the supplicant when the supplicant needs to obtains a packet
from EAPHost to send to the authenticator. **EapHostPeerGetSendPacket** is called when the supplicant receives the [EapHostPeerResponseAction](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) enumerator from the server.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `pcbSendPacket` [out]

A pointer to a DWORD that specifies the maximum size, in bytes, of the buffer pointed to by *ppSendPacket*. **EapHostPeerGetSendPacket** on return is the size of the actual data pointed to by *ppSendPacket*.

### `ppSendPacket` [out]

A pointer to a pointer to a buffer that contains the packet data returned by the EAP module. The buffer is allocated by EAPHost.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)