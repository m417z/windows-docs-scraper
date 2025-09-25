# DXGK_GPUPCAPS structure

## Description

A kernel-mode display driver uses the **DXGK_GPUPCAPS** structure to identify its GPU partitioning (GPU-P) capabilities.

## Members

### `Caps`

Union containing the capability flags for the GPU-P device.

### `Caps.VirtualMachineHibernation`

The driver sets this bit if it supports guest hibernation for GPU-P devices. The support for guest hibernation is optional and not required for driver certification. A VM that has hibernation enabled and a GPU-P adapter added will fail to start if the driver doesn't support guest hibernation.

### `Caps.HotDriverUpdate`

The driver sets this bit if it supports hot driver updates for GPU-P devices.

### `Caps.LiveMigration`

The driver sets this bit if it supports [live migration for GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices). Added in Windows 11, version 24H2 (WDDM 3.2).

### `Caps.ScatterMapReserve`

The driver sets this bit if it supports *DxgkDdiSetVirtualGpuResources2, which will be added in a future release. Added in Windows 11, version 24H2 (WDDM 3.2).

### `Caps.Reserved`

Reserved.

### `Caps.Value`

The UINT value that represents the combined bitfields of the GPU-P capabilities.

## Remarks

The KMD must fill out these caps in response to a [**DXGKQAITYPE_GPUPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) request. The OS queries for these during device initialization after it calls [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) and only if the adapter supports GPU partitioning.

## See also

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)