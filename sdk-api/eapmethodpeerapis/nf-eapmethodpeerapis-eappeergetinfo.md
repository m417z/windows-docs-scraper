# EapPeerGetInfo function

## Description

Obtains a set of function pointers for an implementation of the EAP peer method *EapPeerGetInfo* currently loaded on the EAPHost service.

## Parameters

### `pEapType` [in]

A pointer to an [EAP_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_type) structure that contains the vendor data on the implementer of the APIs pointed to by the members of this structure.

### `pEapInfo` [out]

A pointer to an [EAP_PEER_METHOD_ROUTINES](https://learn.microsoft.com/windows/win32/api/eapmethodpeerapis/ns-eapmethodpeerapis-eap_peer_method_routines) structure that contains the function pointers to EAP method-specific implementations of the APIs that correspond to supplicant calls made to the peer-based EAPHost.

### `ppEapError` [out]

 A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that receives any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

Every EAP peer method DLL must implement the following APIs:

* [EapPeerInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinitialize)
* [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession)
* [EapPeerGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetidentity)
* [EapPeerSetCredentials](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetcredentials)
* [EapPeerProcessRequestPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerprocessrequestpacket)
* [EapPeerGetResponsePacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresponsepacket)
* [EapPeerGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresult)
* [EapPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetuicontext)
* [EapPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetuicontext)
* [EapPeerGetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresponseattributes)
* [EapPeerSetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetresponseattributes)
* [EapPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerendsession)
* [EapPeerShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeershutdown)

These APIs correspond to calls made by a supplicant, and serve as a proxy between the supplicant's API calls and the public APIs exposed on the EAP method DLL. Therefore, when a supplicant makes a call to a peer-based EAPHost to establish an authentication session or to perform an operation during that session, the EAPHost calls the corresponding implemented function on the EAP method DLL with the parameters provided. The EAP method functions are managed by pointers to their respective entry points.

The other functions in the EAP Peer Method API set are called by a peer-based EAPHost without a corresponding supplicant call, and are used for connection validation or user interface invocation operations.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)