# D3DWDDM2_0DDI_VIDEO_DECODER_BUFFER_DESC1 structure

## Description

**D3DWDDM2_0DDI_VIDEO_DECODER_BUFFER_DESC1** is used with [VideoDecoderSubmitBuffers1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecodersubmitbuffers1) to submit one or more buffer for decoding.

## Members

### `hResource`

A handle to the resource object that was created through a call to [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource).

### `BufferType`

The type of buffer, specified as a member of the **D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE** enumeration.

### `DataOffset`

The offset of the relevant data from the beginning of the buffer, in bytes.

**Important** This value must be zero.

### `DataSize`

Size of the relevant data.

### `pIV`

A pointer to a buffer that contains an initialization vector (IV) for encrypted data. If the decode buffer does not contain encrypted data, set this member to **NULL**.

### `IVSize`

The size of the buffer specified in the **pIV** member. If **pIV** is **NULL**, set this member to zero.

### `pSubSampleMappingBlock`

A pointer to an array of [D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_sub_sample_mapping_block) structures, which indicate exactly which bytes in the decode buffer are encrypted and which are in the clear. If the decode buffer does not contain encrypted data, set this member to **NULL**.

Values in the sub sample mapping blocks are relative to the start of the decode buffer.

### `SubSampleMappingCount`

The number of [D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_sub_sample_mapping_block) structures specified in the **pSubSampleMappingBlocks** member. If **pSubSampleMappingBLocks** is **NULL**, set this member to zero.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_video_decoder_sub_sample_mapping_block)