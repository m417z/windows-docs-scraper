# _DXGK_POWER_RUNTIME_COMPONENT structure

## Description

Describes information about a *power component* such as a graphics processing engine, a display device, or a block of memory.

## Members

### `StateCount`

Defines the number of idle states (F-states) for the power component.

### `States`

A [DXGK_POWER_RUNTIME_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_state) structure that defines information about every idle state.

**DXGK_MAX_F_STATES** is the maximum number of F-states that a power component can have. In Windows 8, **DXGK_MAX_F_STATES** is defined to have a value of 8.

### `ComponentMapping`

A [DXGK_POWER_COMPONENT_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_mapping) structure that defines the standard component types of the DirectX graphics kernel subsystem (Dxgkrnl.sys) that describe the power component.

### `Flags`

A [DXGK_POWER_COMPONENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags) structure that specifies power state transition information.

### `ComponentGuid`

A GUID that identifies the power component. This GUID is used by the Power Engine Plug-in (PEP).

### `ComponentName`

A name for the power component. This name is used by GPU profiling tools and is not passed to the PEP.

### `ProviderCount`

Defines the number of other power components that need to be active before this power component becomes active.

### `Providers`

Specifies the indices of other power components that need to be active before this power component becomes active. Each index value must be less than the total number of power components.

## Remarks

Each power component must be mapped to an engine, a display, a memory segment, or another similar device component. The DirectX graphics kernel subsystem detects the idle state of engines, displays, and memory segments.

>[!NOTE]
>Memory segments were removed from Windows 8 but are available in Windows 8.1 and later.

Multiple power components should not be mapped to the same engine (node), to the same memory segment, or to the same VidPN source or target. A power component can be used with only one engine, memory segment, or VidPN source.

## See also

[DXGK_POWER_COMPONENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_flags)

[DXGK_POWER_COMPONENT_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_component_mapping)

[DXGK_POWER_RUNTIME_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_state)