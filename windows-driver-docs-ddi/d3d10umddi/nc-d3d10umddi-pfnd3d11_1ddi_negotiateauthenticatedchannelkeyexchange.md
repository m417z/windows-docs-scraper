# PFND3D11_1DDI_NEGOTIATEAUTHENTICATEDCHANNELKEYEXCHANGE callback function

## Description

Establishes a session key for an authenticated channel.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCAuthChannel`

A handle to an authenticated channel object that was created through a call to the [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

### `DataSize`

The size, in bytes, of the data in the *pData* array.

### `pData`

A pointer to a byte array that contains the encrypted session key.

## Return value

**NegotiateAuthenticatedChannelKeyExchange** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The session key for the authenticated channel was negotiated successfully.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The *pData* parameter references a buffer that contains a session key for the authenticated channel. This key buffer must contain 256 bytes of data and must be encrypted by using the RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) algorithm with the public key from the authenticated channel certificate.

The key exchange for an authenticated channel is identical to the key exchange for the Output Protection Manager (OPM) interface. However, the OPM key buffer contains additional data besides the session key.

> [!NOTE]
> The same certificate can be used for the authenticated channel and OPM session key.

## See also

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)