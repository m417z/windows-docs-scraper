# IDirect3DCryptoSession9::EncryptionBlt

## Description

Reads encrypted data from a protected surface.

## Parameters

### `pSrcSurface`

Pointer to the protected surface.

### `pDstSurface`

Pointer to a surface that receives the encrypted data.

### `DstSurfaceSize`

The size of the surface memory that *pDstSurface* points to, in bytes. The size must be aligned to the value of **BlockAlignmentSize** in the driver capabilities structure; see Remarks.

### `pIV`

Pointer to a buffer that receives the initialization vector (IV). The caller allocates this buffer, but the driver generates the IV.

If the encryption type is **D3DCRYPTOTYPE_AES128_CTR** (128-bit AES-CTR), *pIV* points to a [D3DAES_CTR_IV](https://learn.microsoft.com/windows/desktop/medfound/d3daes-ctr-iv) structure. When the driver generates the first IV, it initializes the structure to a random number. For each subsequent IV, the driver simply increments the **IV** member of the structure, ensuring that the value always increases. This procedure enables the application to validate that the same IV is never used more than once with the same key pair.

For other encryption types, a different structure might be used, or the encryption might not use an IV.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the driver supports this method, it sets the **D3DCPCAPS_ENCRYPTEDREADBACK** flag in the capabilities structure returned by the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method.

If the driver sets the **D3DCPCAPS_ENCRYPTEDREADBACKKEY** capabilities flag, it means the driver uses a separate key to encrypt the data. To get this key, call the [IDirect3DCryptoSession9::GetEncryptionBltKey](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getencryptionbltkey) method. Otherwise, the driver uses the session key to encrypt the data.

Allocate the destination surface (*pDstSurface*) as follows:

1. Call [IDirect3DCryptoSession9::GetSurfacePitch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getsurfacepitch) to get the stride of the protected surface.
2. Call the [GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method to get the value of the **BufferAlignmentStart** and **BlockAlignmentSize** members in the [D3DCONTENTPROTECTIONCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcontentprotectioncaps) structure.
3. Calculate the minimum size of the surface memory as *SysMemSize* = protected surface stride × protected surface height.
4. Add padding to accommodate the values of **BufferAlignmentStart** and **BlockAlignmentSize**.
5. Allocate a buffer in system memory, with size equal to *SysMemSize* (including padding).
6. If the address of the system memory buffer is not aligned to the value of **BufferAlignmentStart**, calculate a memory-aligned pointer that is an offset from the start of the buffer.
7. Call [IDirect3DDevice9Ex::CreateOffscreenPlainSurfaceEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-createoffscreenplainsurfaceex) to create the destination surface. Pass the memory-aligned pointer as the shared-resource handle (*pSharedHandle*).

This method has the following limitations:

* The method cannot read back subrectangles or partially encrypted surfaces.
* The protected surface must be either an offscreen plain surface or a render target.
* The destination surface must be a system-memory surface, created with the proper alignment, as described earlier.
* The protected surface cannot be multisampled.
* The method does not support stretching or colorspace conversion.

If you lock the destination surface, the stride reported in the [D3DLOCKED_RECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlocked-rect) structure might not match the stride of the protected surface. When you interpret the data, however, always use the stride of the protected surface.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)