# DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION_3 callback function

## Description

Implemented by the client driver to set the level of optimization used to control the brightness of a panel.

## Parameters

### `Context` [in]

Context pointer provided when querying the interface.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `OptimizationLevel` [in]

A value of type [DXGK_BACKLIGHT_OPTIMIZATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_backlight_optimization_level) that indicates the optimization level of brightness control.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code defined in ntstatus.h.

## Prototype

```cpp
//Declaration

DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION_3 DxgkBrightnessSetBacklightOptimization3;

// Definition

NTSTATUS DxgkBrightnessSetBacklightOptimization3
(
	PVOID Context
	ULONG ChildUid
	DXGK_BACKLIGHT_OPTIMIZATION_LEVEL OptimizationLevel
)
{...}

DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION_3

```