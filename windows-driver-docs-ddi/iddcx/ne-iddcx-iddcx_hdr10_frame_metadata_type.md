## Description

A **IDDCX_HDR10_FRAME_METADATA_TYPE** enumeration value tells the driver which type of HDR10 metadata to use with a frame.

## Constants

### `IDDCX_HDR10_FRAME_METADATA_TYPE_UNINITIALIZED:0`

Indicates that an **IDDCX_HDR10_FRAME_METADATA_TYPE** variable has not yet been assigned a meaningful value.

### `IDDCX_HDR10_FRAME_METADATA_TYPE_DEFAULT:1`

Indicates that the driver should use the data last sent by the OS in a call to [**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata) for the monitor associated with this swapchain.

### `IDDCX_HDR10_FRAME_METADATA_TYPE_UNCHANGED:2`

Indicates the driver should use the same HDR metadata that was used with the last frame (either default or new from the older frame).

### `IDDCX_HDR10_FRAME_METADATA_TYPE_NEW:3`

Indicates to the driver that the accompanying [**IDDCX_HDR10_FRAME_METADATA::NewMetaData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_frame_metadata) contains valid metadata to use with this frame. The driver must also keep this metadata in case the next **IDDCX_HDR10_FRAME_METADATA_TYPE** is **IDDCX_HDR10_FRAME_METADATA_TYPE_UNCHANGED**. This metadata should not replace the metadata sent in a call to [**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata).

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata)

[**IDDCX_HDR10_FRAME_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_frame_metadata)

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)