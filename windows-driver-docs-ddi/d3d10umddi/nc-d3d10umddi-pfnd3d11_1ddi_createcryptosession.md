# PFND3D11_1DDI_CREATECRYPTOSESSION callback function

## Description

Creates a cryptographic session to encrypt video content that is sent to the display miniport driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCreateData`

A pointer to a [D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession) structure. This structure specifies the attributes of the cryptographic session to be created.

### `hCryptoSession`

A handle to the driver's private data for the cryptographic session. For more information, see the Remarks section.

### `hRTCryptoSession`

A handle to the cryptographic session that the driver should use when it calls back into the Direct3D runtime.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The authenticated channel was created successfully. |
| **D3DDDIERR_DEVICEREMOVED** | The graphics adapter was removed. |
| **D3DDDIERR_UNSUPPORTEDCRYPTO** | A cryptographic type was specified that is not supported by the decode profile. |
| **E_OUTOFMEMORY** | Memory was not available to complete the operation. |

## Remarks

The Direct3D runtime calls *CreateCryptoSession* to create a cryptographic session that the runtime uses to manage a session key and to perform cryptographic operations for video content that is stored in protected memory.

The runtime calls *CreateCryptoSession* after it has called the driver's [CalcPrivateCryptoSessionSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatecryptosessionsize) to determine the size in bytes for the private data that the driver requires for the cryptographic session. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the cryptographic session.

When the runtime calls *CreateCryptoSession*, it passes the handle to the private data memory in the *hCryptoSession* parameter. This handle is actually a pointer to the memory.

The driver must keep track of the handle to the display device that was used to create the cryptographic session. The driver should fail all subsequent calls that use this created cryptographic session, such as [NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange), if the display device that is specified in those calls is different from the display device that was used to create the cryptographic session.

If the **DecodeProfile** member of the [D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession) structure is set to **NULL_GUID**, the cryptographic session will not be used for DirectX Video Acceleration (DXVA) decoding. If **DecodeProfile** is not set to **NULL_GUID**, the driver should fail the call with **D3DDDIERR_UNSUPPORTEDCRYPTO** if the **CryptoType** member is set to a cryptographic type that is not supported by the decode profile.

## See also

[CalcPrivateCryptoSessionSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatecryptosessionsize)

[D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)