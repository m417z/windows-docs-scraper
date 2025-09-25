# EapPeerGetResponsePacket function

## Description

Obtains a response packet from the EAP method.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

### `pcbSendPacket` [in, out]

A pointer to a value that contains the size in bytes of the buffer allocated for the response packet. On return, this parameter receives a pointer to the actual size in bytes of *pSendPacket*.

### `pSendPacket` [out]

A pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the response packet.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

**EapPeerGetResponsePacket** is called by EAPHost on the EAP method to obtain a response packet. EAPHost only calls this API when the action code from a prior call indicates that a packet is available.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)