# IddCxAdapterSetRenderAdapter function

## Description

**IddCxAdapterSetRenderAdapter** sets the preferred render adapter on which to render the swapchains for the specified adapter.

## Parameters

### `AdapterObject` [in]

Adapter object of the adapter for which the rendering adapter preference is being set.

### `pInArgs` [in]

Pointer to an [**IDARG_IN_ADAPTERSETRENDERADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adaptersetrenderadapter) structure containing input arguments to the function.

## Remarks

An indirect display driver (IDD) can call **IddCxAdapterSetRenderAdapter** at anytime to change the preferred render adapter. The driver can use Dxgi enumeration to find the required render adapter LUID.

The OS will use the ID driver's preferred render adapter where possible. In some cases (for example, when the preferred render adapter is PnpStopped), the OS may choose a different adapter. The OS passes the actual render adapter used for a swapchain to the driver in the [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain) callback.

**IddCxAdapterSetRenderAdapter** can be called at any time to change the render LUID. The OS will immediately try to use this new render adapter for all active monitors, re-creating any existing swapchains onto it. Users might see some visual glitches/artifacts as the OS re-configures the desktop composition. To avoid glitches, if the driver knows the render adapter to use at startup time, the driver should call **IddCxAdapterSetRenderAdapter** before adding monitors and only change it while paths are active if the user has explicitly requested it, for example via a device companion application.

**IddCxAdapterSetRenderAdapter** is supported for both console and remote ID adapters.

## See also

[IDARG_IN_ADAPTERSETRENDERADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adaptersetrenderadapter)