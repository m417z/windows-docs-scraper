# _DXVAHDDDI_BLT_STATE_TARGET_RECT_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_TARGET_RECT_DATA structure describes data that specifies the target rectangle of the output.

## Members

### `Enable` [in]

A Boolean value that specifies whether the driver should use the **TargetRect** member or the entire output surface as the target. The default value is **FALSE**, which indicates that the entire output surface is the target.

### `TargetRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the target rectangle in the coordinates of the output surface. This member is relevant only when the **Enable** member is set to **TRUE**. The default value is (0,0,0,0).

## Remarks

If the **Enable** member is set to **TRUE** and the target rectangle that the **TargetRect** member specifies is not within the output surface, the intersection of the target rectangle and the output surface is used as the target rectangle.

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)