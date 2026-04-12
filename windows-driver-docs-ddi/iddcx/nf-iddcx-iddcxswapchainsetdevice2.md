# IddCxSwapChainSetDevice2 function

## Description

An OS callback function the driver calls within its SetSwapChain routine to setup the swap-chain with a particular DXGI device.

## Parameters

### `SwapChainObject` [in]

The **IDDCX_SWAPCHAIN** object previously passed to the driver in a call to [EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain).

### `pInArgs` [in]

A pointer to an [IDARG_IN_SWAPCHAINSETDEVICE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_swapchainsetdevice2) structure that contains the input arguments of the function.

## Return value

The method returns S_OK if the operation succeeds, otherwise an appropriate HRESULT error code.

## Remarks

A driver can call **IddCxSwapChainSetDevice2** to associate a device object used to process swapchain surface objects. The driver must set the **IDARG_IN_SWAPCHAINSETDEVICE2::Type** field and the corresponding pointer in the **IDARG_IN_SWAPCHAINSETDEVICE2::Device** union.

> [!NOTE]
> A driver is responsible for checking the adapter specified by **[IDARG_IN_SETSWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setswapchain).RenderAdapterLuid** in a call to the driver's **EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN** callback supports D3D12 and, in the case D3D12 isn't available, D3D11 can still be used. Drivers can check for D3D12 support in a number of ways, one of which is to obtain an **IDXGIAdapter** object using [**EnumAdapterByLuid**](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgifactory4-enumadapterbyluid) and then try calling **D3D12CreateDevice**.

```cpp
    ComPtr<IDXGIFactory4> pFactory;
    ComPtr<IDXGIAdapter3> pRenderAdapter;
    ComPtr<ID3D12Device> pD3d12Device;

    HRESULT Result = CreateDXGIFactory2(0, IID_PPV_ARGS(&pFactory));
    if (!FAILED(Result))
    {
        // Assume RenderAdapterLuid is obtained from IDARG_IN_SETSWAPCHAIN and passed to this routine
        LUID renderAdapterLuid = /* obtain from IDARG_IN_SETSWAPCHAIN */;

        Result = pFactory->EnumAdapterByLuid(renderAdapterLuid, IID_PPV_ARGS(&pRenderAdapter));
        if (!FAILED(Result))
        {
            Result = D3D12CreateDevice(pRenderAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&pD3d12Device));

            if (FAILED(Result))
            {
                // No D3D12, fall back to using D3D11
            }
            else
            {
                // D3D12 can be used with this swapchain
            }
        }
    }
```

> [!NOTE]
> An IddCx 1.11 driver can still call [**IddCxSwapChainSetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice) to associate an IDXGIDevice object with a swapchain.

## See also

[**IDDCX_SWAPCHAIN_DEVICE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_swapchain_device_type)

[**IDARG_IN_SWAPCHAINSETDEVICE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_swapchainsetdevice2)

[IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions)