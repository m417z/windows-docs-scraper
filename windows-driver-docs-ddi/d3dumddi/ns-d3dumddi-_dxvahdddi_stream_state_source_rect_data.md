# _DXVAHDDDI_STREAM_STATE_SOURCE_RECT_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_SOURCE_RECT_DATA structure describes stream-state data that specifies the source rectangle of the input stream. The driver scales the source rectangle within the input surface to the destination rectangle within the output surface.

## Members

### `Enable` [in]

A Boolean value that specifies whether the driver should use the **SourceRect** member or the entire input surface as the source. The default value is **FALSE**, which indicates that the entire input surface is the source.

### `SourceRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the source rectangle in the coordinates of the input surface. This member is relevant only when the **Enable** member is set to **TRUE**. The default value is (0,0,0,0).

## Remarks

If the **Enable** member is set to **TRUE** and the source rectangle that the **SourceRect** member specifies is not within the input surface, the intersection of the source rectangle and the input surface is used as the source rectangle.

The application can use the source rectangle to specify the active rectangle (dirty region) of the source surface.

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)