# DXGK_WDDMDEVICECAPS structure

## Description

The **DXGK_WDDMDEVICECAPS** structure identifies the kernel-mode driver's WDDM capabilities.

## Members

### `WDDMVersion`

The capabilities of a display miniport driver that the driver provides through a call to its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function. This value is the same as the **WDDMVersion** value in [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure.

## Remarks

A kernel-mode driver returns its WDDM capabilities in this structure, in response to a [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) request for a [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) value of type **DXGKQAITYPE_WDDMDEVICECAPS**.

The OS queries for these capabilities during device initialization, after [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) returns but before [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) is called.