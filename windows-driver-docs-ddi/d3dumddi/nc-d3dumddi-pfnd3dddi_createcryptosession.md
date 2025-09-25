# PFND3DDDI_CREATECRYPTOSESSION callback function

## Description

The **CreateCryptoSession** function creates a crypto session that the Direct3D runtime uses to manage a session key and to perform crypto operations into and out of protected memory.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

pData [in, out]

A pointer to a [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Microsoft Direct3D runtime can use.

## Return value

**CreateCryptoSession** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The crypto session is successfully created. |
| **E_OUTOFMEMORY** | [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) could not allocate the required memory for it to complete. |
| **D3DDDIERR_NOTAVAILABLE** | The driver does not support the GUID that is specified in the CryptoTypemember of the [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) structure or the NULL_GUID (all zeros) is specified in the CryptoTypemember. |
| **D3DDDIERR_UNSUPPORTEDCRYPTO** | The driver does not support the crypto type for the specified decode type. |

## Remarks

If the **DecodeProfile** member of the [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) structure is NULL_GUID, the crypto session will not be used for DirectX Video Acceleration (DirectX VA) decoding. If **DecodeProfile** is not **NULL** GUID, the driver should fail with D3DDDIERR_UNSUPPORTEDCRYPTO if the crypto type in the **CryptoType** member is not supported by the decode profile.

The driver returns a handle for the crypto session in the **hCryptoSession** member of [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) that the runtime passes in all subsequent crypto session calls (for example, [CryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_cryptosessionkeyexchange)).

The driver must keep track of the display device (**hDevice**) that was used to create the crypto session. The driver should fail all subsequent calls that use this created crypto session if the display device that is specified in those calls is different from the display device that was used to create the crypto session.

## See also

[CryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_cryptosessionkeyexchange)

[D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession)