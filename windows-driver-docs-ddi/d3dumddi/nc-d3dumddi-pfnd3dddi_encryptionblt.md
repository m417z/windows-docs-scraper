# PFND3DDDI_ENCRYPTIONBLT callback function

## Description

The *EncryptionBlt* function reads encrypted data from a protected surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_ENCRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_encryptionblt) structure that describes the parameters of the encrypted bit-block transfer (bitblt) operation.

## Return value

*EncryptionBlt* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The encrypted bitblt operation is successfully performed.|
|E_OUTOFMEMORY|EncryptionBlt could not allocate the required memory for it to complete.|
|D3DDDIERR_NOTAVAILABLE|The driver does not support the EncryptionBlt function.|

## Remarks

Hardware and drivers can optionally support *EncryptionBlt*. Some hardware might also require to use a separate key to decrypt the data that is read back. The driver returns this key in a block of memory that the **pIV** member of [D3DDDIARG_ENCRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_encryptionblt) points to.

If the driver and hardware use a separate key for the encryption bitblt, the application must recognize this fact and use the key.

If the crypto type is D3DCRYPTOTYPE_AES128_CTR, **pIV** points to a D3DAES_CTR_IV structure that the application allocates. However, the actual contents of the D3DAES_CTR_IV structure are filled in by the driver and hardware. When the driver and hardware generate the first initialization vector, they should initialize the **IV** member of the D3DAES_CTR_IV structure to a random number (that is not too big). Each subsequent initialization vector should simply increment the **IV** member, which ensures that the **IV** always increases in value. This fact enables the application to validate that the same **IV** is never used multiple times with the same key pair.

*EncryptionBlt* cannot read back sub-rectangles. *EncryptionBlt* also cannot read back partially encrypted buffers because many of the hardware-based solutions do not allow non-encrypted reads from protected memory.

The Direct3D runtime verifies that the destination surface specified by the **DstSubResourceIndex** member of D3DDDIARG_ENCRYPTIONBLT is in system memory and that no stretching, color space conversion, and so on is performed. An application should ensure that the system memory buffer is properly aligned and that the buffer's size matches the source surface. The driver should verify the memory alignment and the buffer size (**DstResourceSize** member of D3DDDIARG_ENCRYPTIONBLT) and fail if these conditions are not correct.

## See also

[D3DDDIARG_ENCRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_encryptionblt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)