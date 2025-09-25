## Description

The **IDDCX_HDR10_FRAME_METADATA** structure contains HDR10 metadata to use with a frame.

## Members

### `Type`

An [**IDDCX_HDR10_FRAME_METADATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_hdr10_frame_metadata_type) value that tells the driver which type of HDR10 metadata to use with this frame.

### `NewMetaData`

If **Type** is **IDDCX_HDR10_FRAME_METADATA_TYPE_NEW**, **NewMetaData** is an [**IDDCX_HDR10_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_metadata) structure that contains the new metadata block to use with this frame.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IDDCX_HDR10_FRAME_METADATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_hdr10_frame_metadata_type)

[**IDDCX_HDR10_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_metadata)

[**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)