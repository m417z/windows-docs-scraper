# IDirect3DCryptoSession9::DecryptionBlt

## Description

Writes encrypted data to a protected surface.

## Parameters

### `pSrcSurface`

A pointer to the surface that contains the source data.

### `pDstSurface`

A pointer to the protected surface where the encrypted data is written.

### `SrcSurfaceSize`

The size of the surface memory that *pSrcSurface* points to, in bytes. The size must be aligned to the value of **BlockAlignmentSize** in the driver capabilities structure; see Remarks.

### `pEncryptedBlockInfo`

A pointer to a [D3DENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows/desktop/medfound/d3dencrypted-block-info) structure, or **NULL**.

If the driver supports partially encrypted buffers, *pEncryptedBlockInfo* indicates which portions of the buffer are encrypted. If the entire surface is encrypted, set this parameter to **NULL**.

To check whether the driver supports partially encrypted buffers, call [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) and check for the **D3DCPCAPS_PARTIALDECRYPTION** capabilities flag. If the driver does not support partially encrypted buffers, set this parameter to **NULL**.

### `pContentKey`

A pointer to a buffer that contains a content encryption key, or **NULL**. To query whether the driver supports the use of content keys, call [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) and check for the **D3DCPCAPS_CONTENTKEY** capabilities flag.

If the driver supports content keys, use the content key to encrypt the surface. Encrypt the content key using the session key, and place the resulting cipher text in *pContentKey*. If the driver does not support content keys, use the session key to encrypt the surface and set *pContentKey* to **NULL**.

### `pIV`

A pointer to a buffer that contains the initialization vector (IV).

If the encryption type is **D3DCRYPTOTYPE_AES128_CTR**, the buffer is a [D3DAES_CTR_IV](https://learn.microsoft.com/windows/desktop/medfound/d3daes-ctr-iv) structure. The caller allocates the structure and generates the IV. When you generate the first IV, initialize the structure to a random number. For each subsequent IV, simply increment the **IV** member of the structure, ensuring that the value always increases. This procedure enables the driver to validate that the same IV is never used more than once with the same key pair.

For other encryption types, a different structure might be used, or the encryption might not use an IV.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all hardware or drivers support this functionality for all cryptographic types.

The source surface must be a system memory surface created with the proper alignment restrictions. The buffer must be large enough to accommodate the pitch and height of the protected surface, plus padding to accommodate the starting alignment restrictions and block transfer size.

Specifically, you should allocate the source surface as follows:

1. Call [IDirect3DCryptoSession9::GetSurfacePitch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getsurfacepitch) to get the stride of the protected surface.
2. Call the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method to get the value of the **BufferAlignmentStart** and **BlockAlignmentSize** members in the [D3DCONTENTPROTECTIONCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcontentprotectioncaps) structure.
3. Calculate the minimum size of the surface memory as *SysMemSize* = protected surface stride × protected surface height.
4. Add padding to accommodate the values of **BufferAlignmentStart** and **BlockAlignmentSize**.
5. Allocate a buffer in system memory, with size equal to *SysMemSize* (including padding).
6. If the address of the system memory buffer is not aligned to the value of **BufferAlignmentStart**, calculate a memory-aligned pointer that is an offset from the start of the buffer.
7. Call [IDirect3DDevice9Ex::CreateOffscreenPlainSurfaceEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-createoffscreenplainsurfaceex) to create the source surface. Pass the memory-aligned pointer as the shared-resource handle (*pSharedHandle*).

If you lock the surface, the stride reported in the [D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect) structure might not match the stride of the protected surface. When you interpret the data, however, always use the stride of the protected surface.

This method does not support writing to subrectangles of the surface.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)