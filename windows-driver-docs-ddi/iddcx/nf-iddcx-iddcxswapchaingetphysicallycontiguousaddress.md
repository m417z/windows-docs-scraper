## Description

**IddCxSwapChainGetPhysicallyContiguousAddress** retrieves the physical address of the specified swapchain's currently acquired surface.

## Parameters

### `SwapChainObject` [in]

The [IDDCX_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object used to query the physical address of the currently acquired surface.

### `pSurfaceAddresss` [out]

Pointer to a PHYSICAL_ADDRESS variable that is filled in with either the physical address of a surface or nullptr.

## Return value

**IddCxSwapChainGetPhysicallyContiguousAddress** returns S_OK on success and indicates a valid physical pointer in **pSurface**. If the initial request to allocate primaries in physically contiguous memory could not be satisfied then this method will return E_NOINTERFACE. If a surface has not been currently acquired, or if **pSurface** is nullptr then this method will return E_INVALIDARG.

## Remarks

**IddCxSwapChainGetPhysicallyContiguousAddress** looks up the currently acquired surface of the specified swapchain and first performs a wait for any pending render commands. Once the wait is successful, it retrieves the physical address of the surface if the initial request succeeded, and then performs a cache flush and invalidation on the range that contains the surface.

## See also

[**IDDCX_ADAPTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags)

[**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer)