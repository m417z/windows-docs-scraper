# D3D11_VIDEO_DECODER_BUFFER_DESC1 structure

## Description

Describes a compressed buffer for decoding.

## Members

### `BufferType`

The type of buffer.

### `DataOffset`

The offset of the relevant data from the beginning of the buffer, in bytes. This value must be zero.

### `DataSize`

Size of the relevant data.

### `pIV`

A pointer to a buffer that contains an initialization vector (IV) for encrypted data. If the decode buffer does not contain encrypted data, set this member to NULL.

### `IVSize`

The size of the buffer specified in the *pIV* parameter. If *pIV* is NULL, set this member to zero.

### `pSubSampleMappingBlock`

A pointer to an array of [D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_decoder_sub_sample_mapping_block) structures, which indicates exactly which bytes in the decode buffer are encrypted and which are in the clear. If the decode buffer does not contain encrypted data, set this member to NULL.

Values in the sub sample mapping blocks are relative to the start of the decode buffer.

### `SubSampleMappingCount`

The number of [D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_decoder_sub_sample_mapping_block) structures specified in the *pSubSampleMappingBlocks* parameter. If *pSubSampleMappingBlocks* is NULL, set this member to zero.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)