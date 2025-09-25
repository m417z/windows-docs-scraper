# D3D11_VIDEO_DECODER_BUFFER_DESC structure

## Description

Describes a compressed buffer for decoding.

## Members

### `BufferType`

The type of buffer, specified as a member of the [D3D11_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type) enumeration.

### `BufferIndex`

Reserved.

### `DataOffset`

The offset of the relevant data from the beginning of the buffer, in bytes. This value must be zero.

### `DataSize`

### `FirstMBaddress`

The macroblock address of the first macroblock in the buffer. The macroblock address is given in raster scan order.

### `NumMBsInBuffer`

The number of macroblocks of data in the buffer. This count includes skipped macroblocks.

### `Width`

Reserved. Set to zero.

### `Height`

Reserved. Set to zero.

### `Stride`

Reserved. Set to zero.

### `ReservedBits`

Reserved. Set to zero.

### `pIV`

A pointer to a buffer that contains an initialization vector (IV) for encrypted data. If the decode buffer does not contain encrypted data, set this member to **NULL**.

### `IVSize`

The size of the buffer specified in the **pIV** parameter. If **pIV** is **NULL**, set this member to zero.

### `PartialEncryption`

If **TRUE**, the video surfaces are partially encrypted.

### `EncryptedBlockInfo`

A [D3D11_ENCRYPTED_BLOCK_INFO](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_encrypted_block_info) structure that specifies which bytes of the surface are encrypted.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoContext::SubmitDecoderBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-submitdecoderbuffers)