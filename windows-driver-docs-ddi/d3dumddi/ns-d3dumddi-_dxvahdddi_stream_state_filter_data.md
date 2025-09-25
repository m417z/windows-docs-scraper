# _DXVAHDDDI_STREAM_STATE_FILTER_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_FILTER_DATA structure describes stream-state data that specifies the filter level.

## Members

### `Enable` [in]

A Boolean value that specifies whether the filter is enabled. The default value is **FALSE**, which indicates that the filter is disabled.

### `Level` [in]

An INT value that specifies the filter level. The default value is the value from the **Default** member of the [DXVAHDDDI_FILTER_RANGE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_filter_range_data) structure.

## Remarks

The level that is specified in the **Level** member must be within the range that the driver supplies in the members of the [DXVAHDDDI_FILTER_RANGE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_filter_range_data) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPFILTERRANGE value set.

## See also

[DXVAHDDDI_FILTER_RANGE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_filter_range_data)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)