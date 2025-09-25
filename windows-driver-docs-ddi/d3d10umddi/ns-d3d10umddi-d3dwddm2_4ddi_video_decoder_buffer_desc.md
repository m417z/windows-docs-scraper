# D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC structure

## Description

Represents additional decode parameters.

## Members

### `hResource`

The source decoder buffer.

### `BufferType`

The type of buffer.

### `DataOffset`

The offset of the relevant data from the beginning of the buffer, in bytes. This value must be zero.

### `DataSize`

Size of the relevant data.

### `pIV`

A pointer to a buffer that contains an initialization vector (IV) for encrypted data. If the decode buffer does not contain encrypted data, set this member to NULL.

### `IVSize`

The size of the buffer specified in the pIV parameter. If pIV is NULL, set this member to zero.

### `pSubSampleMappingBlock`

A pointer to an array of D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK structures, which indicates exactly which bytes in the decode buffer are encrypted and which are in the clear. If the decode buffer does not contain encrypted data, set this member to NULL.

>**Note** Values in the sub sample mapping blocks are relative to the start of the decode buffer.

### `SubSampleMappingCount`

The number of D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK structures specified in the pSubSampleMappingBlocks parameter. If pSubSampleMappingBlocks is NULL, set this member to zero.

### `cBlocksStripeEncrypted`

Indicates the number of 16-byte BLOCKS that are encrypted in any given encrypted region mapping, as defined by the CENS and CBCS schemes in the common encryption spec.

If this value is zero:

* All bytes each encrypted region mapping are encrypted, i.e. the CENC or CBC1 scheme is being used.
* cBlocksStripeClear must also be zero.

If this value is non-zero, cBlocksStripeClear must also be non-zero.

>**Note** This value will typically be ZERO or ONE in real-world content, but the spec merely recommends this and does not require it

### `cBlocksStripeClear`

Indicates the number of 16-byte BLOCKS that are clear in any given encrypted region mapping, as defined by the CENS and CBCS schemes in the common encryption spec.

If this value is zero, all bytes each encrypted region mapping are encrypted, i.e. the CENC or CBC1 scheme is being used.

## Remarks

## See also