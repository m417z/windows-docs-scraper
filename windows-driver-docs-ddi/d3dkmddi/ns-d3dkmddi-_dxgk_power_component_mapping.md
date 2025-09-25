# _DXGK_POWER_COMPONENT_MAPPING structure

## Description

Used in the [DXGK_POWER_RUNTIME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_component).**ComponentMapping** member to define the standard component types of the Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys) that describe the power component.

## Members

### `ComponentType`

A [DXGK_POWER_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_power_component_type)-typed value that indicates the power component type that is reported by the display miniport driver to the DirectX graphics kernel subsystem.

### `EngineDesc`

Information about the engine.

### `EngineDesc.NodeIndex`

The index of the engine (node).

### `MonitorRefreshDesc`

Information about the monitor refresh.

### `MonitorRefreshDesc.VidPnSourceID`

An identifier of one of the video present sources associated with the video present network object.

### `MonitorDesc`

Information about the monitor.

### `MonitorDesc.VidPnTargetID`

An identifier of one of the video present targets associated with the VidPN object.

### `MemoryDesc`

Information about the memory.

### `MemoryDesc.SegmentID`

Memory segment ID.

### `SharedDesc`

Shared power component description.

### `SharedDesc.SharedTypeFlag`

Flag that indicates the shared type.

### `SharedDesc.DriverCustomValueSet`

Custom shared value.

### `SharedDesc.SharedType`

Shared type.

## Remarks

Each component must be mapped to an engine, display, memory or other. Dxgkrnl will detect the idle state for engines, displays and memory segments.

* Multiple power components should not be mapped to the same engine (node).
* Multiple power components should not to be mapped to the same memory segment.
* Multiple power components should not be mapped to the same VidPn Source or Target.
* The same power component can be used with only one engine, memory segment or VidPnSourceId.

## See also

[DXGK_POWER_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_power_component_type)

[DXGK_POWER_RUNTIME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_component)