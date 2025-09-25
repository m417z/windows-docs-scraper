# D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK structure

## Description

**D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK** is used with [VideoDecoderSubmitBuffers1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecodersubmitbuffers1) to describe the decoder buffer sub sample mapping block size.

## Members

### `ClearSize`

The number of clear (non-encrypted) bytes at the start of the block.

### `EncryptedSize`

The number of encrypted bytes following the clear bytes.

## Remarks

Values in the sub sample mapping blocks are relative to the start of the decode buffer.

## See also

[VideoDecoderSubmitBuffers1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecodersubmitbuffers1)