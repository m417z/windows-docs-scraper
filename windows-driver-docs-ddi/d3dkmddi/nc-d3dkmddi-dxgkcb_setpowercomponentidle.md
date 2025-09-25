# DXGKCB_SETPOWERCOMPONENTIDLE callback function

## Description

A display miniport driver calls **DXGKCB_SETPOWERCOMPONENTIDLE** to notify the DirectX graphics kernel subsystem that a power component is no longer needed. After this function returns, the display miniport driver must not change the component's hardware settings.

## Parameters

### `hAdapter` [in]

A handle to the display adapter. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `ComponentIndex` [in]

The power component index specified by [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**pInputData** in a call to the [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Remarks

The display miniport driver can call this function for any type of power component, even if the DirectX graphics kernel subsystem manages the idle state of the component.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbSetPowerComponentIdle** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface). Each call to this function must be paired with a call to the [**DXGKCB_SETPOWERCOMPONENTACTIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive) function.

When this function is called, the active reference count of the component is decreased by 1. The [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) maintains the reference count and places the component into a lower F-state only when the reference count becomes zero.

This function must be called at IRQL <= DISPATCH_LEVEL. It can be called at IRQL = DISPATCH_LEVEL only if the component type is **DXGK_POWER_COMPONENT_OTHER**.

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGKCB_SETPOWERCOMPONENTACTIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)