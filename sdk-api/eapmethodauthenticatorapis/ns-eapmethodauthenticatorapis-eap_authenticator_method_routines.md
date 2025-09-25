# EAP_AUTHENTICATOR_METHOD_ROUTINES structure

## Description

Contains a set of function pointers to the EAPHost Authenticator Method APIs.

## Members

### `dwSizeInBytes`

The implementer defined structure version.

**Note** Values for this field are not defined by Microsoft.

### `pEapType`

A pointer to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains the vendor information on the implementer of the APIs pointed to by this structure's members.

### `EapMethodAuthenticatorInitialize`

Function pointer to [EapMethodAuthenticatorInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorinitialize).

#### pEapType

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) enumeration value that specifies the type of EAP authentication to use for this session.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapMethodAuthenticatorBeginSession`

Function pointer to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession).

#### dwFlags

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

#### pwszIdentity

Zero-terminated Unicode string that contains the identity of the user to authenticate.

#### pAttributeArray

A pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) array structure that specifies the EAP attributes of the entity to authenticate.

#### dwSizeOfConnectionData

Specifies the size, in bytes, of the connection data buffer provided in *pConnectionData*.

#### pConnectionData

A pointer to a byte buffer that contains the opaque configuration data BLOB.

#### dwMaxSendPacketSize

Specifies the maximum size, in bytes, of an EAP packet sent during the session.

#### pSessionHandle

Receives a pointer to an **EAP_SESSION_HANDLE** structure that contains the unique ID for the new EAP authentication session on server EAPHost.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `EapMethodAuthenticatorUpdateInnerMethodParams`

Function pointer to [EapMethodAuthenticatorUpdateInnerMethodParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorupdateinnermethodparams).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### dwFlags

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

#### pwszIdentity

Zero-terminated Unicode string that contains the updated identity of the user to authenticate.

#### pAttributeArray

A pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) array structure that specifies the updated EAP attributes of the entity to authenticate.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

### `EapMethodAuthenticatorReceivePacket`

Function pointer to [EapMethodAuthenticatorReceivePacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorreceivepacket).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### cbReceivePacket

The size, in bytes, of *pReceivePacket*.

#### pReceivePacket

A pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains an EAP authentication session packet received from the supplicant by the server EAPHost.

#### pEapOutput

Receives a pointer to an [EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ne-eapauthenticatoractiondefine-eap_method_authenticator_response_action) enumeration value that indicates the next action the supplicant must take in the EAP authentication session.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

### `EapMethodAuthenticatorSendPacket`

Function pointer to [EapMethodAuthenticatorSendPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsendpacket).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### bPacketId

Specifies a numeric ID value for the packet to send.

#### pcbSendPacket

Specifies the maximum size, in bytes, of the packet to send. On return, this parameter receives the size, in bytes, of the packet returned in *pEapPacket*.

#### pSendPacket

Receives a pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the packet to send to the supplicant.

#### pTimeout

Receives a pointer to an [EAP_AUTHENTICATOR_SEND_TIMEOUT](https://learn.microsoft.com/windows/win32/api/eapauthenticatortypes/ne-eapauthenticatortypes-eap_authenticator_send_timeout) value that specifies the timeout for the packet.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory)

### `EapMethodAuthenticatorGetAttributes`

Function pointer to [EapMethodAuthenticatorGetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetattributes).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### pAttribs

Receives a pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains an array of EAP authentication response attributes for the supplicant.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory)

### `EapMethodAuthenticatorSetAttributes`

Function pointer to [EapMethodAuthenticatorSetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsetattributes).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### pAttribs

Pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains an array of new EAP authentication response attributes to set for the supplicant on EAPHost.

#### pEapOutput

Receives a pointer to an [EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ne-eapauthenticatoractiondefine-eap_method_authenticator_response_action) enumeration value that specifies the suggested action the supplicant should take as a response to the updated attributes.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

### `EapMethodAuthenticatorGetResult`

Function pointer to [EapMethodAuthenticatorGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetresult).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)

#### pResult

Receives a pointer to a [EAP_METHOD_AUTHENTICATOR_RESULT](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eap_method_authenticator_result) structure that contains the authentication results.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

### `EapMethodAuthenticatorEndSession`

Function pointer to [EapMethodAuthenticatorEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorendsession).

#### sessionHandle

**EAP_SESSION_HANDLE** value that contains the specific handle for the EAP authentication session to close on the server EAPHost. This handle is obtained by a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession).

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

### `EapMethodAuthenticatorShutdown`

Function pointer to [EapMethodAuthenticatorShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorshutdown).

#### pEapType

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) enumeration value that specifies the type of EAP authentication used in the session.

#### ppEapError

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## Remarks

Every EAP authenticator method DLL must have public implementations of the following APIs on it.

* [EapMethodAuthenticatorInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorinitialize)
* [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)
* [EapMethodAuthenticatorUpdateInnerMethodParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorupdateinnermethodparams)
* [EapMethodAuthenticatorReceivePacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorreceivepacket)
* [EapMethodAuthenticatorSendPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsendpacket)
* [EapMethodAuthenticatorGetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetattributes)
* [EapMethodAuthenticatorSetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsetattributes)
* [EapMethodAuthenticatorGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetresult)
* [EapMethodAuthenticatorEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorendsession)
* [EapMethodAuthenticatorShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorshutdown)

These APIs are called on an EAP authenticator method when an authenticator (server) EAPHost receives a specific corresponding remote procedure call from a peer (client) EAP method. Note that a complete one-to-one correspondence does not exist between EAP peer methods and EAP authenticator methods; the specific EAP authenticator method API calls must be made based on the requirements of your implementation of the EAP authenticator method API calls.

## See also

[EAPHost Authenticator Method Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-structures)

[EapMethodAuthenticatorGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetinfo)