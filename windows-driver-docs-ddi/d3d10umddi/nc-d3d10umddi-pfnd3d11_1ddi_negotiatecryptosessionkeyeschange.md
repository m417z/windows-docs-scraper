# PFND3D11_1DDI_NEGOTIATECRYPTOSESSIONKEYESCHANGE callback function

## Description

Establishes a session key for a cryptographic session object.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the cryptographic session object that was created through a call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `DataSize`

The size, in bytes, of the data in the *pData* array.

### `pData`

A pointer to a byte array that contains the encrypted session key.

## Return value

*NegotiateCryptoSessionKeyExchange* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The session key for the cryptographic session was negotiated successfully.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The *pData* parameter references a buffer that contains a session key for the cryptographic session. The key exchange mechanism depends on the type of the encryption algorithm that is used by the cryptographic session.

For sessions that use the RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) algorithm, the key buffer must contain 256 bytes of data and must be encrypted by using the RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) algorithm with the public key from the cryptographic session certificate.

The key exchange for a cryptographic session is identical to the key exchange for the Output Protection Manager (OPM) interface. However, the OPM key buffer contains additional data besides the session key.

**Note** The same certificate can be used for the cryptographic session and OPM session key.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)