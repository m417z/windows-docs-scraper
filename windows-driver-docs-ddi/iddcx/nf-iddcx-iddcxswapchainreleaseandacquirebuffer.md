# IddCxSwapChainReleaseAndAcquireBuffer function

## Description

An indirect display driver calls **IddCxSwapChainReleaseAndAcquireBuffer** to release the current buffer in the swap chain and acquire a new one. IDDs that report [FP16 support](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) must call [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2) instead.

## Parameters

### `SwapChainObject`

[in] The swap-chain object previously passed by the OS to the driver in a [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain) call.

### `pOutArgs`

[out] Pointer to an [**IDARG_OUT_RELEASEANDACQUIREBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer) structure in which the output arguments of the function are returned.

## Return value

**IddCxSwapChainReleaseAndAcquireBuffer** returns S_OK on success; otherwise it returns an appropriate error code.

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)