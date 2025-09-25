# PFND3D11_1DDI_ENCRYPTIONBLT callback function

## Description

Reads encrypted data from a protected surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCryptoSession`

A handle to the driver's private data for the cryptographic session. This handle was created by the Direct3D runtime and passed to the driver in the call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `hSrcResource`

A handle to the resource that contains the source data.

### `hDstResource`

A pointer to the resource where the encrypted data is to be written.

### `IVSize`

The size, in bytes, of the initialization vector (IV).

### `pIV`

A pointer to a block of memory that contains the initialization vector that is required to encrypt the bitblt data. For more information, see the Remarks section.

**Note**

If *pIV* is NULL, the graphics adapter does not require a separate initialization vector to encrypt the data. That is, the session key is used to encrypt the data.

## Remarks

This function has the following limitations:

* The function cannot read back subrectangles or partially encrypted surfaces.
* The function cannot read back partially encrypted buffers. Many hardware-based encryption solutions will not allow nonencrypted reads from protected memory.
* The protected surface must be either an off-screen plain surface or a render target.
* The destination surface must be a system-memory surface that was created by using the proper alignment, as described earlier.
* The protected surface cannot be multisampled.
* The function does not support stretching or color space conversion.

For 128-bit AES-CTR encryption, the *pIV* parameter points to a [D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv) structure that is allocated by the application. However, the actual contents of this structure are filled in by the driver or graphics adapter. When the first IV is generated, the driver or adapter initializes the **IV** member of this structure to a random number. For each subsequent IV, the caller increments the **IV** member, ensuring that the value always increases. This procedure enables the application to validate that the same IV is never used more than once with the same key pair.

For other encryption types, a different structure might be used, or the encryption might not use an IV.

**Note** This function does not honor a Direct3D version 11 predicate that may have been set.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv)