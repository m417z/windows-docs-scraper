## Description

The **IDARG_IN_RELEASEANDACQUIREBUFFER2** structure contains input arguments for the [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2) function.

## Members

### `Size`

[in] Total size of this structure, in bytes.

### `AcquireSystemMemoryBuffer`

[in] Boolean value. When a driver sets this field to TRUE, the OS fills out an [**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info) structure in [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2). This is equivalent to a pre-1.10 driver calling [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquiresystembuffer) instead of [**IddCxSwapChainReleaseAndAcquireBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer).

### `pD3D12CommandQueue`

Pointer to an [ID3D12CommandQueue] object used to submit commands that use the swap chain surface as input.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

In order to support D3D12, the **IDARG_IN_RELEASEANDACQUIREBUFFER2** structure used in calls to [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2) has been extended. Drivers supporting D3D12 that passed an **ID3D12Device** in a call to [**IddCxSwapChainSetDevice2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice2) must provide a **ID3D12CommandQueue** object that's used to read from the swap chain surface. The driver must also pass the extended [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) structure with the **IDDCX_METADATA2::Size** field set correctly so the OS can set a new valid flag and the new D3D12 surface field.

For more information about D3D12 support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.11-updates).

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)