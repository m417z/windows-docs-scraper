# PFND3DDDI_DECRYPTIONBLT callback function

## Description

The **DecryptionBlt** function writes data to a protected surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) structure that describes the parameters of the decrypted bit-block transfer (bitblt) operation.

## Return value

**DecryptionBlt** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The decrypted bitblt operation is successfully performed.|
|E_OUTOFMEMORY|DecryptionBlt could not allocate the required memory for it to complete.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the DecryptionBlt function.|

## Remarks

Hardware and drivers can optionally support **DecryptionBlt** for some crypto types.

If the calling application requires the use of a content key, the application uses the content key to encrypt the data, and the session key to encrypt the content key before passing the content key in the block of memory that the **pContentKey** member of [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) points to. If **pContentKey** is **NULL**, it indicates that the application used the session key to encrypt the data.

If the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function previously created the encryption session with the **CryptoType** member of the [D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession) structure set to D3DCRYPTOTYPE_AES128_CTR, the **pIV** member of [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) points to the [DXVADDI_PVP_HW_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_hw_iv) structure and contains the initialization vector that the application used to encrypt the buffer. The driver's **DecryptionBlt** function should fail if it determines that the initialization vector was previously used for the same content key (or session key if the content key is not used). The application should increment the **IV** member of the DXVADDI_PVP_HW_IV structure for each buffer that the application encrypts. Therefore, the driver's **DecryptionBlt** function can fail if the **IV** member is less than or equal to the previous **IV** value that was passed to **DecryptionBlt**.

If the driver and hardware support partially encrypted buffers, the **pEncryptedBlockInfo** member of [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) indicates the portions of the buffer that are encrypted and the portions that are not encrypted. If the entire buffer is encrypted, **pEncryptedBlockInfo** should be **NULL**.

**DecryptionBlt** cannot write sub-rectangles.

The Direct3D runtime verifies that the source surface specified by the **SrcSubResourceIndex** member of the [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) structure is in system memory and that no stretching, color space conversion, and so on is performed. An application should ensure that the system memory buffer is properly aligned and that the buffer's size matches the destination surface. The driver should verify the memory alignment and the buffer size (**SrcResourceSize** member of D3DDDIARG_DECRYPTIONBLT) and fail if these conditions are not correct..

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3DDDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createcryptosession)

[D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)