# IDDCX_FRAME_STATISTICS structure

## Description

The **IDDCX_FRAME_STATISTICS** structure provides information about the current frame being processed.

## Members

### `Size`

Total size of this structure, in bytes.

### `PresentationFrameNumber`

The frame number provided in a prior call to [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) (or [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer)).

### `FrameStatus`

An [**IDDCX_FRAME_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_frame_status) value that indicates the overall status of processing this frame.

### `ReEncodeNumber`

A zero-based number to indicate the number of times the same frame has been encoded and sent. Re-encodes can be the result of the OS providing the same frame and frame number to the driver to encode or the driver having to re-encode outside of the normal OS presentation to satisfy the protocol.

### `FrameSliceTotal`

The number of slices the driver processes the frame in. If slices are not used, then this should be set to the value one.

### `CurrentSlice`

The zero-based slice number being reported. If slicing is not supported, then the driver should always set this to the value zero.

### `FrameAcquireQpcTime`

System QPC time at which the driver acquired the buffer from the OS.

### `FrameProcessingStepsCount`

The size of the frame step array pointed to by **pFrameProcessingStep**.

### `pFrameProcessingStep`

An array of [**IDDCX_FRAME_STATISTICS_STEP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics_step) structures that describe the frame processing steps the driver performed.

### `SendStartQpcTime`

Marks the time when the driver started transmission for this slice to the device. **SendStartQpcTime** marks the time the driver started calling the transmit APIs, not when the data actually starts being transmitted.

### `SendStopQpcTime`

Marks the time when the driver stopped transmission for this slice to the device. **SendStopQpcTime** marks the time the driver stopped calling the transmit APIs, not when the data actually stops being transmitted.

### `SendCompleteQpcTime`

Marks the time when the send was reported as complete by the OS. This is an optional time stamp that can be used if the driver uses an asynchronous transmit API and a completion routine. In the event the driver does not have an asynchronous completion routine, this value should be set to zero.

### `Flags`

A [**IDDCX_FRAME_STATISTICS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_frame_statistics_flags) value that indicates how the frame was altered by the driver.

### `ProcessedPixelCount`

The total number of pixels processed in this frame.

### `FrameSizeInBytes`

Total size of the data sent to the device for this frame. This value includes all the slices.

## See also

[**IDDCX_FRAME_STATISTICS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_frame_statistics_flags)

[**IDDCX_FRAME_STATISTICS_STEP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics_step)

[**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer)