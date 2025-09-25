# DXGK_BRIGHTNESS_SET_3 callback function

## Description

*DxgkBrightnessSet3* Directs the driver to linearly ramp the brightness from its current brightness level to a target brightness level over a specified length of time. A set brightness transition can be interrupted by a new DxgkBrightnessSet3 call. The driver should transition from the current brightness level in the interrupted ramp.

## Parameters

### `Context` [in]

Context pointer provided when querying the interface.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `pIn:` [in]

A [DXGK_BRIGHTNESS_SET_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_set_in) structure that contains the input parameters for the set brightness call.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code defined in ntstatus.h.

## Prototype

```cpp
//Declaration

DXGK_BRIGHTNESS_SET_3 DxgkBrightnessSet3;

// Definition

NTSTATUS DxgkBrightnessSet3
(
	PVOID Context
	ULONG ChildUid
	PDXGK_BRIGHTNESS_SET_IN pIn
)
{...}

DXGK_BRIGHTNESS_SET_3

```