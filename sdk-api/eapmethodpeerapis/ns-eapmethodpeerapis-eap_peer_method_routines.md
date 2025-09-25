# EAP_PEER_METHOD_ROUTINES structure

## Description

Contains a set of function pointers to the EAPHost Peer Method APIs.

## Members

### `dwVersion`

The implementer-defined structure version.

**Note** Values for this field are not defined by Microsoft.

### `pEapType`

A pointer to an [EAP_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_type) structure that contains the vendor information on the implementer of the APIs pointed to by the members of this structure.

### `EapPeerInitialize`

A function pointer for [EapPeerInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinitialize).

#### pEapError

A pointer to the [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerGetIdentity`

A function pointer for [EapPeerGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetidentity).

#### dwflags

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

#### dwSizeofConnectionData

Specifies the size, in bytes, of the connection data buffer provided in *pConnectionData*

#### pConnectionData

A pointer to a byte buffer that contains the opaque configuration data BLOB.

#### dwSizeOfUserData

Specifies the size, in bytes, of the user data buffer provided in *pUserData*.

#### pUserData

A pointer to the user data specific to this authentication used to pre-populate the user data.
When this API is called for the first time, or when a new authentication session starts, this parameter is **NULL**.
Otherwise, set this parameter to the **pUserData** member of the structure pointed to by the *ppResult* parameter received by **EapPeerGetResult**.

#### hTokenImpersonateUser

Specifies a handle to the impersonation token of the user being authenticated. This handle will be **NULL** when doing machine authentication. By using this handle an EAP method can impersonate the user for the purpose of obtaining user specific information such as user name, domain name and credentials.

#### pfInvokeUI

Returns **TRUE** if the user identity and user data blob are not returned successfully, and the method seeks to collect the information from the user through the user interface dialog.

#### pdwSizeOfUserDataOut

Specifies the size, in bytes, of the *ppUserDataOut* buffer.

#### ppUserDataOut

A pointer to a pointer to the returned user data. The data is passed to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession) as input *pUserData*.

#### ppwszIdentity

 A pointer to the returned user identity. The pointer will be included in the identity response packet and returned to the server.

#### ppEapError

A pointer to the pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerBeginSession`

A function pointer for [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### dwFlags

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the new EAP authentication session behavior.

#### pAttributeArray

Pointer to an [EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) array structure that specifies the EAP attributes of the entity to authenticate.

#### hTokenImpersonateUser

Specifies a handle to the user impersonation token to use in this session.

#### dwSizeOfConnectionData

Specifies the size, in bytes, of the connection data buffer provided in *pConnectionData*.

#### pConnectionData

Pointer to a byte buffer that contains the opaque configuration data BLOB.

#### dwSizeOfUserData

Specifies the size in bytes of the user data buffer provided in *pUserData*.

#### pUserData

Pointer to a byte buffer that contains the opaque user data BLOB.

#### dwMaxSendPacketSize

Specifies the maximum size in bytes of an EAP packet sent during the session. If the method needs to
send a packet larger than the maximum size, the method must accommodate fragmentation and reassembly.

#### pSessionHandle

Pointer to a **EAP_SESSION_HANDLE** structure that contains the unique ID for the new EAP authentication session on EAPHost

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerSetCredentials`

A function pointer for [EapPeerSetCredentials](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetcredentials).

#### sessionHandle

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### pwszIdentity

Pointer that specifies the user identity for which to set the credentials. This user identity string is obtained by calling the [EapPeerGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetidentity) function.

#### pwszPassword

A pointer that contains the clear text password for the user identity.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerProcessRequestPacket`

A function pointer for [EapPeerProcessRequestPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerprocessrequestpacket).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### cbReceivePacket

The size in bytes of the request packet specified in *pReceivePacket*.

#### pReceivePacket

Pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the request packet to process.

#### pEapOutput

Pointer to an [EapPeerMethodOutput](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eappeermethodoutput) structure that contains the output of the packet process operation.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerGetResponsePacket`

A function pointer for [EapPeerGetResponsePacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresponsepacket).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### pcbSendPacket

Pointer to a value that contains the size in bytes of the buffer allocated for the response packet. On return, this parameter receives a pointer to the actual size in bytes of *pSendPacket*.

#### pSendPacket

Pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the response packet.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerGetResult`

 A function pointer for [EapPeerGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresult).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### reason

Enumeration value that specifies the reason code for the authentication result returned in *ppResult*.

#### ppResult

Pointer to a **EapHostPeerMethodResult** structure that contains the authentication results.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerGetUIContext`

A function pointer for [EapPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetuicontext).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### pdwSizeOfUIContextData

Pointer to a value that specifies the size of the user interface context data byte buffer returned in *ppUIContextData*.

#### ppUIContextData

Pointer to an address that contains a byte buffer with the supplicant user interface context data from EAPHost.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerSetUIContext`

A function pointer for [EapPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetuicontext).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### dwSizeOfUIContextData

Pointer to a value that specifies the size of the UI context data byte buffer provided in *pUIContextData*.

#### pUIContextData

Pointer to an address that contains a byte buffer with the new supplicant UI context data to set on EAPHost.

#### pEapOutput

 A pointer to an [EapPeerMethodOutput](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eappeermethodoutput) structure that contains the output of the packet process operation.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerGetResponseAttributes`

A function pointer for [EapPeerGetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetresponseattributes).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### pAttribs

Receives a pointer to an [EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains an array of EAP authentication response attributes for the supplicant.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerSetResponseAttributes`

A function pointer for [EapPeerSetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetresponseattributes).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### pAttribs

Pointer to an [EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains an array of new EAP authentication response attributes to set for the supplicant on EAPHost.

#### pEapOutput

A pointer to an [EapPeerMethodOutput](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eappeermethodoutput) structure that specifies the suggested action the supplicant should take as a response to the updated attributes.

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerEndSession`

A function pointer for [EapPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerendsession).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session to close on EAPHost. This handle is obtained by a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapPeerShutdown`

A function pointer for [EapPeerShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeershutdown).

#### ppEapError

Pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

Each EAP method DLL must implement the following APIs:

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
* **EapPeerShutdown**

These APIs correspond to calls made by a supplicant, and serve as a proxy between the supplicant's API calls and the public APIs exposed on the EAP method DLL. Therefore, when a supplicant makes a call to a peer-based EAPHost to establish an authentication session or to perform an operation during that session, EAPHost calls the corresponding implemented function on the EAP method DLL with the parameter data provided. The EAP method functions are managed by pointers to their respective entry points.

The other functions in the EAP Peer Method API set are called by a peer-based EAPHost without a corresponding supplicant call, and are used for connection validation or user interface raising operations.

## See also

[EAPHost Peer Method Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-peer-method-structures)

[EapPeerGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetinfo)