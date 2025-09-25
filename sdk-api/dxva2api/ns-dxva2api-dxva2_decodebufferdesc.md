# DXVA2_DecodeBufferDesc structure

## Description

Describes a buffer sent from a decoder to a DirectX Video Acceleration (DXVA) device.

## Members

### `CompressedBufferType`

Identifies the type of buffer passed to the accelerator. Must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DXVA2_PictureParametersBufferType** | Picture decoding parameter buffer. |
| **DXVA2_MacroBlockControlBufferType** | Macroblock control command buffer. |
| **DXVA2_ResidualDifferenceBufferType** | Residual difference block data buffer. |
| **DXVA2_DeblockingControlBufferType** | Deblocking filter control command buffer. |
| **DXVA2_InverseQuantizationMatrixBufferType** | Inverse quantization matrix buffer. |
| **DXVA2_SliceControlBufferType** | Slice-control buffer. |
| **DXVA2_BitStreamDateBufferType** | Bitstream data buffer. |
| **DXVA2_MotionVectorBuffer** | Motion vector buffer. |
| **DXVA2_FilmGrainBuffer** | Film grain synthesis data buffer. |

### `BufferIndex`

Reserved. Set to zero.

### `DataOffset`

Specifies the offset of the relevant data from the beginning of the buffer, in bytes. Currently this value must be zero.

### `DataSize`

Specifies the amount of relevant data in the buffer, in bytes. The location of the last byte of content in the buffer is **DataOffset** + **DataSize** − 1.

### `FirstMBaddress`

Specifies the macroblock address of the first macroblock in the buffer. The macroblock address is given in raster scan order.

### `NumMBsInBuffer`

Specifies the number of macroblocks of data in the buffer. This count includes skipped macroblocks. This value must be zero if the data buffer type is one of the following: picture decoding parameters, inverse-quantization matrix, AYUV, IA44/AI44, DPXD, Highlight, or DCCMD.

### `Width`

Reserved. Set to zero.

### `Height`

Reserved. Set to zero.

### `Stride`

Reserved. Set to zero.

### `ReservedBits`

Reserved. Set to zero.

### `pvPVPState`

Pointer to a byte array that contains an initialization vector (IV) for encrypted data. If the decode buffer does not contain encrypted data, set this member to **NULL**.
If the decode buffer contains encrypted data, the contents of **pvPVPState** depends on the type of encryption. For **D3DCRYPTOTYPE_AES128_CTR**, the **pvPVPState** member points to a [DXVA2_AES_CTR_IV](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_aes_ctr_iv) structure.

## Remarks

This structure corresponds closely to the [DXVA_BufferDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/dxva/ns-dxva-_dxva_bufferdescription) structure in DXVA 1, but some of the fields are no longer used in DXVA 2.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)