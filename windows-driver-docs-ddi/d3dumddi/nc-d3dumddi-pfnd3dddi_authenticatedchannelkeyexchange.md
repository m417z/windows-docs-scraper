# PFND3DDDI_AUTHENTICATEDCHANNELKEYEXCHANGE callback function

## Description

The **AuthenticatedChannelKeyExchange** function negotiates the session key.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

pData [in, out]

A pointer to a [D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_authenticatedchannelkeyexchange) structure that describes a buffer that contains the session key, which the authenticated channel uses.

## Return value

**AuthenticatedChannelKeyExchange** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The session key is successfully negotiated. |
| **E_OUTOFMEMORY** | [AuthenticatedChannelKeyExchange]() could not allocate the required memory for it to complete. |

## Remarks

The **pData** member in the [D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_authenticatedchannelkeyexchange) structure points to a buffer that contains a secret key that an application previously RSAES-OAEP-encrypted with the public key from the driver's authenticated channel certificate. The actual size of the buffer is 256 bytes. This exchange is identical to how the [Output Protection Manager](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-output-protection-manager) (OPM) key exchange works, except the OPM buffer contains additional data besides the session key. The same certificate that is used for OPM key exchange can be used for the authenticated channel.

The driver decrypts this secret key and uses the secret key in calls to the driver's [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) and [QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel) functions to calculate One-key Cipher Block Chaining (CBC)-mode message authentication codes (OMACs).

## See also

[D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_authenticatedchannelkeyexchange)