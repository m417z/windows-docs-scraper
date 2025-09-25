# D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC structure

## Description

Describes a compressed buffer for Microsoft DirectX Video Acceleration (DXVA) decoding.

## Members

### `hResource`

A handle to the resource that will receive the decrypted and decode frame buffers.

### `BufferType`

The type of buffer, specified as a constant value of the [D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type) enumeration.

In D3d10umddi.h, [D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type) and **D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE** are defined as the same type.

### `BufferIndex`

Reserved for system use.

### `DataOffset`

The offset of the relevant data from the beginning of the buffer, in bytes. This value must be zero.

### `DataSize`

The offset of the relevant data from the beginning of the buffer, in bytes. This value must be zero.

### `FirstMBaddress`

The macroblock address of the first macroblock in the buffer. The macroblock address is given in raster scan order.

### `NumMBsInBuffer`

The number of macroblocks of data in the buffer. This count includes skipped macroblocks.

### `Width`

Reserved for system use. Set to zero.

### `Height`

Reserved for system use. Set to zero.

### `Stride`

Reserved for system use. Set to zero.

### `ReservedBits`

Reserved for system use. Set to zero.

### `pIV`

A pointer to a [D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv) structure that contains an initialization vector (IV) for the frame buffer data that was encrypted by using the 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption algorithm.

If the decode buffer does not contain any encrypted data, set **pIV** to **NULL**.

### `IVSize`

The size of the buffer specified in the **pIV** member. If **pIV** is **NULL**, set this member to zero.

### `PartialEncryption`

If **TRUE**, the video surfaces are partially encrypted.

### `EncryptedBlockInfo`

A [D3D11_1DDI_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info) structure that specifies which bytes of the surface are encrypted.

## Syntax

```cpp
typedef struct D3D11_1DDI_VIDEO_DECODERR_BUFFER_DESC {
  D3D10DDI_HRESOURCE                   hResource;
  D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE BufferType;
  UINT                                 BufferIndex;
  UINT                                 DataOffset;
  UINT                                 DataSize;
  UINT                                 FirstMBaddress;
  UINT                                 NumMBsInBuffer;
  UINT                                 Width;
  UINT                                 Height;
  UINT                                 Stride;
  UINT                                 ReservedBits;
  void                                 *pIV;
  UINT                                 IVSize;
  BOOL                                 PartialEncryption;
  D3D11_1DDI_ENCRYPTED_BLOCK_INFO      EncryptedBlockInfo;
} D3D11_1DDI_VIDEO_DECODER_BUFFER_DESC;
```

## See also

[D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type)

[D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv)

[D3D11_1DDI_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_encrypted_block_info)