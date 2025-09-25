# DRT_SECURITY_PROVIDER structure

## Description

The **DRT_SECURITY_PROVIDER** structure defines the DRT interface that must be implemented by a security provider.

## Members

### `pvContext`

This member is specified by the application when passing the **DRT_SECURITY_PROVIDER** structure to the [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen) function.

The DRT treats it as an opaque pointer, and passes it as the first parameter to the functions referenced by this structure. An application will use this as a pointer to the security provider state or to the object that implements the security provider functionality.

### `Attach`

Increments the count of references for the Security Provider with a set of DRTs.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

### `Detach`

Decrements the count of references for the Security Provider with a set of DRTs.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

### `RegisterKey`

Called to register a key with the Security Provider.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pRegistration

Pointer to the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure created by an application and passed to the [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) function.

#### pvKeyContext

Pointer to the context data created by an application and passed to the [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) function.

### `UnregisterKey`

Called to deregister a key with the Security Provider.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pKey

Pointer to the key to which the payload is registered.

#### pvKeyContext

Pointer to the context data created by the application and passed to [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey).

### `ValidateAndUnpackPayload`

Called when an Authority message is received on the wire. It is responsible for validating the data received, and for unpacking the service addresses, revoked flag, and nonce from the Secured Address Payload.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pSecuredAddressPayload

Pointer to the payload received on the wire that contains the service addresses, revoked flag, nonce, and any other data required by the security provider.

#### pCertChain

Pointer to the cert chain received in the authority message.

#### pClassifier

Pointer to the classifier received in the authority message

#### pNonce

Pointer to the nonce that was sent in the original **Inquire** or **Lookup** message. This value must be compared to the value embedded in the Secured Address Payload to ensure they are the same. This value is fixed at 16 bytes.

#### pSecuredPayload

Pointer to the application data payload received in the Authority message. After validation, the original data (after decryption, removal of signature, and so on.) is output as *pPayload*.

#### pbProtocolMajor

Pointer to the byte array that represents the protocol major version. This is packed in every DRT packet to identify the version of the security provider in use when a single DRT instance is supporting multiple Security Providers.

#### pbProtocolMinor

Pointer to the byte array that represents the protocol minor version. This is packed in every DRT packet to identify the version of the security provider in use when a single DRT instance is supporting multiple Security Providers.

#### pKey

Pointer to the key to which the payload is registered.

#### pPayload

Pointer to the original payload specified by the remote application. **pPayload.pb** is allocated by the security provider.

#### ppPublicKey

Pointer to a pointer to the number of service addresses embedded in the secured address payload.

#### ppAddressList

Pointer to a pointer to the service addresses that are embedded in the Secured Address Payload. **pAddresses** is allocated by the security provider.

#### pdwFlags

Any DRT flags currently defined only to be the revoked or deleted flag that need to be unpacked for the local DRT instance processing.

**Note** Currently the only allowed value is: **DRT_PAYLOAD_REVOKED**

### `SecureAndPackPayload`

Called when an Authority message is about to be sent on the wire. It is responsible for securing the data before it is sent, and for packing the service addresses, revoked flag, nonce, and other application data into the Secured Address Payload.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pvKeyContext

Contains the context passed into [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) when the key was registered.

#### bProtocolMajor

Pointer to the byte array that represents the protocol major version.

#### bProtocolMinor

Pointer to the byte array that represents the protocol minor version.

#### dwFlags

Any DRT specific flags, currently defined only to be the revoked or deleted flag that need to be packed, secured and sent to another instance for processing.

**Note** Currently the only allowed value is: **DRT_PAYLOAD_REVOKED**

#### pKey

Pointer to the key to which this payload is registered.

#### pPayload

Pointer to the payload specified by the application when calling [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey).

#### pAddressList

Pointer to the service addresses that are placed in the Secured Address Payload.

#### pNonce

Pointer to the nonce that was sent in the original **Inquire** or **Lookup** message. This value is fixed at 16 bytes.

#### pSecuredAddressPayload

Pointer to the payload to send on the wire which contains the service addresses, revoked flag, nonce, and other data required by the security provider. **pSecuredAddressPayload.pb** is allocated by the security provider.

#### pClassifier

Pointer to the classifier to send in the Authority message. **pClassifier.pb** is allocated by the security provider.

#### pSecuredPayload

Pointer to the application data payload received in the Authority message. After validation, the original data (after decryption, removal of signature, and so on.) is output as *pPayload*. **pSecuredPayload.pb** is allocated by the security provider.

#### pCertChain

Pointer to the cert chain to send in the Authority message. **pCertChain.pb** is allocated by the security provider.

### `FreeData`

Called to release resources previously allocated for a security provider function.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pv

Specifies what data to free.

### `EncryptData`

Called when the DRT sends a message containing data that must be encrypted. This function is only called when the DRT is operating in the **DRT_SECURE_CONFIDENTIALPAYLOAD** security mode defined by [DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode).

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pRemoteCredential

Contains the credential of the peer that will receive the protected message.

#### dwBuffers

Contains the length of the *pDataBuffers* and *pEncryptedBuffers*.

#### pDataBuffers

Contains the unencrypted buffer.

#### pEncryptedBuffers

Contains the encrypted content upon completion of the function.

#### pKeyToken

Contains the encrypted session key that can be decrypted by the recipient of the message and used to decrypted the protected fields.

### `DecryptData`

Called when the DRT receives a message containing encrypted data. This function is only called when the DRT is operating in the **DRT_SECURE_CONFIDENTIALPAYLOAD** security mode defined by [DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode).

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pKeyToken

Contains the encrypted session key that can be decrypted by the recipient of the message and used to decrypt the protected fields.

#### pvKeyContext

Contains the context passed into [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) when the key was registered.

#### dwBuffers

Contains the size of *pData* buffer.

#### pData

Contains the decrypted data upon completion of the function.

### `GetSerializedCredential`

Called when the DRT must provide a credential used to authorize the local node. This function is only called when the DRT is operating in the **DRT_SECURE_MEMBERSHIP** and **DRT_SECURE_CONFIDENTIALPAYLOAD** security modes defined by [DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode).

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pSelfCredential

Contains the serialized credential upon completion of the function.

### `ValidateRemoteCredential`

Called when the DRT must validate a credential provided by a peer node.

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### pRemoteCredential

Contains the serialized credential provided by the peer node.

### `SignData`

Called when the DRT must sign a data blob for inclusion in a DRT protocol message. This function is only called when the DRT is operating in the **DRT_SECURE_MEMBERSHIP** and **DRT_SECURE_CONFIDENTIALPAYLOAD** security modes defined by [DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode).

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### dwBuffers

Contains the size of the *pDataBuffers* buffer.

#### pDataBuffers

Contains the data to be signed.

#### pKeyIdentifier

Upon completion of this function, contains an index that can be used to select from multiple credentials for use in calculating the signature.

#### pSignature

Upon completion of this function, contains the signature data.

### `VerifyData`

Called when the DRT must verify a signature calculated over a block of data included in a DRT message. This function is only called when the DRT is operating in the **DRT_SECURE_MEMBERSHIP** and **DRT_SECURE_CONFIDENTIALPAYLOAD** security modes defined by [DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode).

#### pvContext

Pointer to the value held by the **pvContext** member of **DRT_SECURITY_PROVIDER**.

#### dwBuffers

Contains the size of the *pDataBuffers* buffer.

#### pDataBuffers

Contains the data over which the signature was calculated.

#### pRemoteCredentials

Contains the credentials of the remote node used to calculate the signature.

#### pKeyIdentifier

Contains an index that may be used to select from multiple credentials provided in *pRemoteCredentials*.

#### pSignature

Contains the signature to be verified.

## See also

[DRT_SECURITY_MODE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_security_mode)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)

[DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey)