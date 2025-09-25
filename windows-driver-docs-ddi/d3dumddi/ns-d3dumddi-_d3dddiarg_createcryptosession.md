# _D3DDDIARG_CREATECRYPTOSESSION structure

## Description

The D3DDDIARG_CREATECRYPTOSESSION structure describes an encryption session to create.

## Members

### `CryptoType` [in]

A GUID that indicates the encryption type, which the driver uses for the encryption session that the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function creates. The GUID can be one of the following:

#### D3DCRYPTOTYPE_AES128_CTR

A GUID that indicates the 128 bit AES-CRT block cipher.

#### D3DCRYPTOTYPE_PROPRIETARY

A GUID that indicates a proprietary encryption algorithm.

### `DecodeProfile`

 [in] A GUID that indicates the DirectX Video Acceleration (DirectX VA) decode profile that the driver uses for the encryption session that the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function creates. The driver uses this decode profile in conjunction with the encryption type that the **CryptoType** member specifies.

### `hCryptoSession` [in/out]

A handle to the encryption session. The user-mode display driver must set this handle to a value that the Microsoft Direct3D runtime can use to identify the encryption session in subsequent calls.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)