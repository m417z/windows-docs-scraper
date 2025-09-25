# DXGK_BRIGHTNESS_GET_3 callback function

## Description

Implemented by the client driver to retrieve the currently active brightness level of an integrated display panel, with details on the brightness transition in progress.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `pOut` [out]

Pointer to a [PDXGK_BRIGHTNESS_GET_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_get_out) structure that contains the output parameters for the get brightness call.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code defined in ntstatus.h.

## Prototype

```cpp
//Declaration

DXGK_BRIGHTNESS_GET_3 DxgkBrightnessGet3;

// Definition

NTSTATUS DxgkBrightnessGet3
(
	PVOID Context
	ULONG ChildUid
	PDXGK_BRIGHTNESS_GET_OUT pOut
)
{...}

DXGK_BRIGHTNESS_GET_3

```