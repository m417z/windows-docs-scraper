# _DXVAHDDDI_STREAM_STATE_DESTINATION_RECT_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_DESTINATION_RECT_DATA structure describes stream-state data that specifies the destination rectangle. The driver scales the source rectangle within the input surface to the destination rectangle within the output surface.

## Members

### `Enable` [in]

A Boolean value that specifies whether the driver should use the **DestinationRect** member or the entire target rectangle as the destination. The default value is **FALSE**, which indicates that the entire target rectangle is the destination.

### `DestinationRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the coordinates of the destination rectangle relevant to the target rectangle. This member is relevant only when the **Enable** member is set to **TRUE**. The default value is empty (0,0,0,0).

## Remarks

If the **Enable** member is set to **TRUE** and the destination rectangle that the **DestinationRect** member specifies is not within the target rectangle, the intersection of the destination rectangle and the target rectangle is used as the destination rectangle.

The application can use the destination rectangle to specify the active rectangle (dirty region) of the destination surface.

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)