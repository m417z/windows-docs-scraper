# _DXVAHDDDI_STREAM_STATE_ASPECT_RATIO_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_ASPECT_RATIO_DATA structure describes stream-state data that specifies the pixel aspect ratio.

## Members

### `Enable` [in]

A Boolean value that specifies whether the pixel aspect ratios are available. The default value is **FALSE**, which indicates that the pixel aspect ratios are not available.

### `SourceAspectRatio` [in]

A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies the pixel aspect ratio of the source. The default is (1, 1).

### `DestinationAspectRatio` [in]

A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies the pixel aspect ratio of the destination. The default is (1, 1).

## Remarks

The driver might require the source and destination pixel aspect ratios to achieve the best result.

The **DXVAHDDDI_STREAM_STATE_ASPECT_RATIO** stream state is best set along with the **DXVAHDDDI_STREAM_STATE_FILTER_ANAMORPHIC_SCALING** stream state.

Pixel aspect ratios (0, any value) and (any value, 0) are invalid and causes the driver to return an error.

## See also

[DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational)