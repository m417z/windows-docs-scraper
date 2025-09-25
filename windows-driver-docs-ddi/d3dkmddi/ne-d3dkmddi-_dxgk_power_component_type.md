# _DXGK_POWER_COMPONENT_TYPE enumeration

## Description

Indicates the power component type that is reported by the display miniport driver to the Microsoft DirectX graphics kernel subsystem.

## Constants

### `DXGK_POWER_COMPONENT_ENGINE`

Indicates that the component is a GPU engine.

**Note** An engine can have only one power component assigned.

### `DXGK_POWER_COMPONENT_MONITOR`

Indicates a monitor that is connected to a VidPN target and can have its power managed. A typical component of this type is an LCD panel backlight.

### `DXGK_POWER_COMPONENT_MONITOR_REFRESH`

Indicates hardware that scans out from a VidPN source and generates a signal for a VidPN target.

A typical component of this type is a self-refreshing monitor, which can display the last frame even if the frame buffer stops sending data to the monitor. The display miniport driver should report this component type only if all monitors that can be driven from the VidPN source are self-refreshing.

### `DXGK_POWER_COMPONENT_MEMORY`

### `DXGK_POWER_COMPONENT_MEMORY_REFRESH`

### `DXGK_POWER_COMPONENT_OTHER`

Indicates a component for which the idle state is managed entirely by the display miniport driver. The DirectX graphics kernel subsystem passes this information to the [Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework).

### `DXGK_POWER_COMPONENT_D3_TRANSITION`

### `DXGK_POWER_COMPONENT_SHARED`

Indicates that the graphics driver supports shared power components.

### `DXGK_POWER_COMPONENT_MAX`

A maximum value that is used for testing purposes.