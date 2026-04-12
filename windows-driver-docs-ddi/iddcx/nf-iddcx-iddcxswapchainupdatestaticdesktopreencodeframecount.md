# IddCxSwapChainUpdateStaticDesktopReencodeFrameCount function

## Description

**IddCxSwapChainUpdateStaticDesktopReencodeFrameCount** overrides the StaticDesktopReencodeFrameCount value specified in the parameters passed to [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync) on a specific swap chain.

## Parameters

### `SwapChainObject` [in]

The **IDDCX_SWAPCHAIN** object previously passed to the driver in a call to [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain).

### `StaticDesktopReencodeFrameCount` [in]

The new StaticDesktopReencodeFrameCount value to use with the specified swap chain.

## Return value

The method returns S_OK if the operation succeeds, otherwise an appropriate HRESULT error code.

## Remarks

Drivers must specify a StaticDesktopReencodeFrameCount in the parameters passed to **IddCxAdapterInitAsync**. A driver can now use
**IddCxSwapChainUpdateStaticDesktopReencodeFrameCount** to override this value on a specific swap chain.

In some scenarios, a driver might decide to change how many reencode frames it wants to receive. The driver can call **IddCxSwapChainUpdateStaticDesktopReencodeFrameCount** to update the number of frames received for a specific swap chain from what was set when the adapter was created. This can be used to set the value from 0 to non-zero, non-zero to zero or just a different non-zero value.

> [!NOTE]
> A reencode frame is indicated by the driver being given a single empty dirty rect alongside a frame.

> [!NOTE]
> If a swap chain for a certain monitor is unassigned and a new one assigned, the reencode count starts at the value specified in the [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync) parameters.

## See also

[IDDCX_ADAPTER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)

[IDARG_IN_ADAPTER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init)