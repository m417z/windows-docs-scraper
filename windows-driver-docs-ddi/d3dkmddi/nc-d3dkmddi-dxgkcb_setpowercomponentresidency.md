# DXGKCB_SETPOWERCOMPONENTRESIDENCY callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_SETPOWERCOMPONENTRESIDENCY** to set the expected residency for a power component of type **DXGK_POWER_COMPONENT_OTHER**.

## Parameters

### `hAdapter` [in]

A handle to the display adapter. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `ComponentIndex` [in]

The power component index specified by [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**pInputData** in a call to the [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

### `Residency` [in]

The expected residency — the maximum time, in units of 100 nanoseconds — that the display miniport driver expects a power component to remain idle after it enters an idle state. The [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) uses this information to select an appropriate idle state for the component that does not violate the requested residency. The expected residency specified by **Residency** remains in effect until the driver calls this function again to update it. See Remarks.

## Remarks

> [!NOTE]
>
> The display miniport driver should call this function only if the component type is **DXGK_POWER_COMPONENT_OTHER**. The DirectX graphics kernel subsystem sets the expected residency value for other component types.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbSetPowerComponentResidency** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

If the power component is in an idle state when this function is called, the [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) might change the component's F-state to meet the expected residency value specified by **Residency**.

If the driver sets **Residency** to a value of **PO_FX_UNKNOWN_TIME** (defined in *Wdm.h*), the Power Engine Plug-in (PEP) might be unable to set the component to an F-state lower than F0.

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)