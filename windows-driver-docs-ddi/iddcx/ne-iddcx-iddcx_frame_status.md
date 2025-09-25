# IDDCX_FRAME_STATUS enumeration

## Description

A **IDDCX_FRAME_STATUS** value indicates the processing status of the frame.

## Constants

### `IDDCX_FRAME_STATUS_UNINITIALIZED:0`

Indicates that an **IDDCX_FRAME_STATUS** variable has not yet been assigned a meaningful value.

### `IDDCX_FRAME_STATUS_COMPLETED:1`

Indicates that the frame was processed completely and sent to the device.

### `IDDCX_FRAME_STATUS_DROPPED:2`

Indicates that the driver stopped processing this frame to start on a newer frame. This normally happens if it is taking a long time to process/transmit the frame.

### `IDDCX_FRAME_STATUS_ERROR:3`

Indicates that the driver stopped processing this frame because the driver hit an internal error.

## See also

[**IDDCX_FRAME_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics)

[**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer)