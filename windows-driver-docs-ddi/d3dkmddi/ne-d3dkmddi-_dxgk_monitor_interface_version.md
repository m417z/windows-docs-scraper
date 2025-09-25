# DXGK_MONITOR_INTERFACE_VERSION enumeration

## Description

The **DXGK_MONITOR_INTERFACE_VERSION** enumeration indicates a particular version of the [monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface).

## Constants

### `DXGK_MONITOR_INTERFACE_VERSION_UNINITIALIZED:0`

Indicates that a variable of type **DXGK_MONITOR_INTERFACE_VERSION** has not yet been assigned a meaningful value.

### `DXGK_MONITOR_INTERFACE_VERSION_V1:1`

Indicates version 1, available in Windows Vista.

### `DXGK_MONITOR_INTERFACE_VERSION_V2:2`

Indicates version 2, available starting in Windows 7.

## Remarks

The **Version** member of the [**DXGK_MONITOR_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface) structure is a value from the **DXGK_MONITOR_INTERFACE_VERSION** enumeration.