# EapPeerProcessRequestPacket function

## Description

Processes a packet received by EAPHost from a supplicant.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

### `cbReceivedPacket` [in]

The size, in bytes, of the request packet specified in *pReceivePacket*.

### `pReceivedPacket` [in]

A pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the request packet to process.

### `pEapOutput` [out]

A pointer to an [EapPeerMethodOutput](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eappeermethodoutput) structure that contains the output of the packet process operation.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)