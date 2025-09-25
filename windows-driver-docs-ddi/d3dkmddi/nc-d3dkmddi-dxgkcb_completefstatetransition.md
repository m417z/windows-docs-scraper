# DXGKCB_COMPLETEFSTATETRANSITION callback function

## Description

**DXGKCB_COMPLETEFSTATETRANSITION** notifies the port driver that a power component has completed the F-state transition.

## Parameters

### `hAdapter` [in]

A handle to the display adapter. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `ComponentIndex` [in]

The power component index specified by [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**pInputData** in a call to the [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Remarks

During component registration the display miniport driver should indicate all power components for which it will need to call the **DXGKCB_COMPLETEFSTATETRANSITION** function by setting the [**DXGK_POWER_COMPONENT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags).**DriverCompletesFStateTransition** member to 1. When this member is set, the driver must call this function either synchronously or asynchronously. Conversely, if this member is not set, the driver should not call this function.

> [!NOTE]
>
> If [**DXGK_POWER_COMPONENT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags).**DriverCompletesFStateTransition** has been set but the driver does not call this function, deadlocks might occur.

The Windows power management framework guarantees that no new transition request will be sent for the component until this function is called.

Usually the port driver expects that when this function returns, the F-state transition is completed. There could be scenarios when the display miniport driver cannot complete the transition synchronously, for example if the display miniport driver cannot complete the transitions at **DISPATCH_LEVEL**, or it needs to activate other power components. This function helps the display miniport driver to complete the F-state transition asynchronously.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl) and then call **DxgkCbCompleteFStateTransition** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGK_POWER_COMPONENT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)