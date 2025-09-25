# DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT callback function

## Description

Called after a new multi-plane overlay configuration has taken effect, allowing the driver to optimize hardware state. Optional for Windows Display Driver Model (WDDM) 2.0 or later drivers that support multi-plane overlays.

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware.

### `pPostPresent`

A pointer to a [DXGKARG_POSTMULTIPLANEOVERLAYPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_postmultiplaneoverlaypresent) structure that describes the new overlay configuration recently committed.

## Return value

**DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT** returns the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|If the routine has been successfully completed. The driver should always return a success code. Failures will result in a bugcheck.|

## Remarks

This function is called from PASSIVE level.

This function is only called when driver sets PostPresentNeeded of [DXGKCB_NOTIFY_MPO_VSYNC_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_notify_mpo_vsync_flags) member of the [DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure in the VSYNC callback.

The driver can use this function to lower voltage levels, clocks, FIFO depths, or any other optimization that can save power.

The driver should not spend significant amount of time in this call because the call blocks the main GPU scheduler thread and delay could lead to present glitches. Time intensive actions should be queued as separate work items by driver and handled in background. In this scenario, any conflicts between the queued item and hardware changes demanded by future pre/post calls should be managed by driver.