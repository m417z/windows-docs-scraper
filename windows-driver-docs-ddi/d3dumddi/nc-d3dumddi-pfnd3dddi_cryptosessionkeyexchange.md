# PFND3DDDI_CRYPTOSESSIONKEYEXCHANGE callback function

## Description

The **CryptoSessionKeyExchange** function negotiates a session key.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_cryptosessionkeyexchange) structure that describes a session key that is used for encryption.

## Return value

**CryptoSessionKeyExchange** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The session key is successfully exchanged. |
| **E_OUTOFMEMORY** | [CryptoSessionKeyExchange]() could not allocate the required memory for it to complete. |

## Remarks

The driver should only support a single key exchange mechanism for each encryption type. Microsoft has standardized the key exchange type D3DKEYEXCHANGE_RSAES_OAEP. However, hardware vendors can use proprietary key exchange mechanisms.

For D3DKEYEXCHANGE_RSAES_OAEP, the **pData** member of the [D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_cryptosessionkeyexchange) structure points to a buffer that contains the session key that an application previously RSAES-OAEP-encrypted with the public key from the driver's crypto session certificate. The actual size of the buffer is 256 bytes. This exchange is identical to how the [Output Protection Manager](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-output-protection-manager) (OPM) key exchange works, except the OPM buffer contains additional data besides the session key. The same certificate that is used for OPM key exchange can be used for the D3DKEYEXCHANGE_RSAES_OAEP key exchange.

## See also

[D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_cryptosessionkeyexchange)