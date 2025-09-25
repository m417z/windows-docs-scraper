## Description

**PFN_IDDCXSWAPCHAINRELEASEANDACQUIREBUFFER2** is a pointer to an OS callback function that releases the buffer from the swap chain and acquires a new buffer.

## Parameters

### `DriverGlobals`

[in] Contains system-defined per-driver data.

### `SwapChainObject`

[in] The swap chain object that the buffer is associated with.

### `pInArgs`

[in] Input arguments for the function.

### `pOutArgs`

[out] Output arguments for the function.

## Return value

**PFN_IDDCXSWAPCHAINRELEASEANDACQUIREBUFFER2** returns an NTSTATUS value that indicates the success or failure of the function.

## Remarks

An indirect display driver (IDD) shouldn't use this function pointer to directly. IDDs should instead call [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2).

## See also

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)