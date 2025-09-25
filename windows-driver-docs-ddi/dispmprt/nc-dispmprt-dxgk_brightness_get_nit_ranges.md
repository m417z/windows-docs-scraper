# DXGK_BRIGHTNESS_GET_NIT_RANGES callback function

## Description

Implemented by the client driver to retrieve a list of supported nit ranges.

## Parameters

### `Context` [in]

Context pointer provided when querying the interface.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `pOut:` [out]

A pointer to a [DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_get_nit_ranges_out) structure that represents the supported brightness ranges of the display panel.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code defined in ntstatus.h.

## Prototype

```cpp
//Declaration

DXGK_BRIGHTNESS_GET_NIT_RANGES DxgkBrightnessGetNitRanges;

// Definition

NTSTATUS DxgkBrightnessGetNitRanges
(
	PVOID Context
	ULONG ChildUid
	PDXGK_BRIGHTNESS_GET_NIT_RANGES_OUT pOut
)
{...}

DXGK_BRIGHTNESS_GET_NIT_RANGES

```