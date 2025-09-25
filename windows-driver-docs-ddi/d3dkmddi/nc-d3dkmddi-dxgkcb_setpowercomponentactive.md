# DXGKCB_SETPOWERCOMPONENTACTIVE callback function

## Description

A display miniport driver calls **DXGKCB_SETPOWERCOMPONENTACTIVE** to access a power component. After this function returns, the display miniport driver can change the component's hardware settings.

## Parameters

### `hAdapter` [in]

A handle to the display adapter. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `ComponentIndex` [in]

The power component index specified by [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**pInputData** in a call to the [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Remarks

Each call to this function must be paired with a call to the [**DXGKCB_SETPOWERCOMPONENTIDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentidle) function to indicate that the component hardware is no longer required.

When this function is called, the active reference count of the component is increased by 1. The [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) maintains the reference count and places the component into a lower F-state only when the reference count becomes zero.

While calling this function, the display miniport driver might receive a call to the [**DxgkDdiSetPowerComponentFState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate) function on another execution thread.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbSetPowerComponentActive** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGKCB_SETPOWERCOMPONENTIDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentidle)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DxgkDdiSetPowerComponentFState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)