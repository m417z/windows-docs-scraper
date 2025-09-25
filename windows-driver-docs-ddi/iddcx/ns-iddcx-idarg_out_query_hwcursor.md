# IDARG_OUT_QUERY_HWCURSOR structure

## Description

The **IDARG_OUT_QUERY_HWCURSOR** structure is the output parameter used by [**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor) to return information about the coordinates and shape of the current cursor.

## Members

### `IsCursorVisible`

[out] A Boolean value that indicates whether the cursor is visible.

### `X`

[out] If the cursor is visible (**IsCursorVisible** = TRUE) then **X** is the *x* screen co-ordinate of the top-left hand pixel in the cursor image. See Remarks.

### `Y`

[out] If the cursor is visible (**IsCursorVisible** = TRUE) then **Y** is the *y* screen co-ordinate of the top-left hand pixel in the cursor image. See Remarks.

### `IsCursorShapeUpdated`

 [out] A Boolean value that indicates whether the cursor shape has been updated since the last time the driver called [**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor). If it has been updated then the OS updates the **CursorShapeInfo** structure and copies the new cursor image data into the [**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor).**pShapeBuffer** buffer.

### `CursorShapeInfo`

[out] A [**IDDCX_CURSOR_SHAPE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_cursor_shape_info) structure in which the OS copies the current cursor information if the cursor is visible. If the cursor is not visible then OS zeroes this structure.

## Remarks

Note that **X** and **Y** can be negative; for example, a hot spot in the center of cursor that is placed in the top-left of the screen.

## See also

[**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor)

[**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2)