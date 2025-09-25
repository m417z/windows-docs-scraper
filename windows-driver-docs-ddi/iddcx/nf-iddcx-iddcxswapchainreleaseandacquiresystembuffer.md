## Description

**IddCxSwapChainReleaseAndAcquireSystemBuffer** releases and acquires buffers from the swapchain.

## Parameters

### `SwapChainObject` [in]

The [IDDCX_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object used for querying the physical address of the currently acquired surface.

### `pOutArgs` [out]

Pointer to a [**IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer) structure in which the resulting information from the release and acquire operation is returned.

## Return value

**IddCxSwapChainReleaseAndAcquireSystemBuffer** returns S_OK on success; otherwise it returns an appropriate error code.

## Remarks

In addition to releasing and acquiring buffers from the swapchain, **IddCxSwapChainReleaseAndAcquireSystemBuffer** also unmaps and unlocks the buffer being released while mapping and locking the buffer being acquired. For this reason, it is not valid to call [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) subsequent to calling this method. The [**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info) structure pointed to by **pBufferInfo** is filled with valid information only on a successful release and acquire as indicated by a return value of S_OK.

## See also

[**IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer)

[**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info)

[**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer)