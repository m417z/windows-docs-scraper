# IddCxSwapChainFinishedProcessingFrame function

## Description

 An OS callback function the driver calls to report all GPU command for processing this frame have been queued

## Parameters

### `SwapChainObject` [in]

The swap-chain object whose current frame is being queried.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

If the driver copies the buffer to a staging surface so it can lock and copy the pixel data to the CPU, then the driver should call this callback once the copy from surface to staging surface has been submitted. If the driver does not call this callback the desktop will not update. It is invalid to call [IddCxSwapChainReleaseAndAcquireBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) before calling **IddCxSwapChainFinishedProcessingFrame**