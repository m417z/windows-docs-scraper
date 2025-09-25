## Description

**IddCxSwapChainInSystemMemory** checks whether buffers for a swapchain are resident in system memory.

## Parameters

### `SwapChainObject` [in]

The [**IDDCX_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object whose allocation is to be checked.

### `pInSystemMemory` [out]

The result of the check. Set to TRUE when buffers are resident in system memory; otherwise set to FALSE.

## Return value

**IddCxSwapChainInSystemMemory** returns S_OK on success; otherwise it returns an appropriate error code. Possible errors include **SwapChainObject** is an invalid swapchain object and **pInSystemMemory** is a null pointer.

## Remarks

The driver can call **IddCxSwapChainInSystemMemory** at any point after [**IddCxSwapChainSetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice) has been called to check if the buffers for the swapchain are resident in system memory. It is recommended that drivers call this method when a new swapchain is being assigned, but are free to call it at any point in the lifecycle of the swapchain object.

When **IddCxSwapChainInSystemMemory** returns TRUE in **pInSystemMemory**, the driver can use either [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) or [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer) for releasing and acquiring buffers from the swapchain. The driver must continue to use that particular method throughout the lifetime of that particular swapchain.

When **IddCxSwapChainInSystemMemory** returns FALSE, the driver must use [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) to release and acquire buffers from the swapchain.

## See also

[**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer)