## Description

The **IDARG_IN_RELEASEANDACQUIREBUFFER2** structure contains input arguments for the [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2) function.

## Members

### `Size`

[in] Total size of this structure, in bytes.

### `AcquireSystemMemoryBuffer`

[in] Boolean value. When a driver sets this field to TRUE, the OS fills out an [**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info) structure in [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2). This is equivalent to a pre-1.10 driver calling [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer) instead of [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer).

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)