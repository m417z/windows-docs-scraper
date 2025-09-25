## Description

An **IDARG_OUT_QUERY_HWCURSOR2** structure is the output parameter used by [**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2) to return information about the current hardware cursor.

## Members

### `IsCursorVisible`

[out] A Boolean value that indicates whether the cursor is visible.

### `X`

[out] If the cursor is visible (**IsCursorVisible** = TRUE) then **X** is the *x* screen co-ordinate of the top-left hand pixel in the cursor image. This field is only valid if **PositionValid** is TRUE. **X** can be negative; for example, when a hot spot in the center of cursor is placed in the top-left of the screen.

### `Y`

[out] If the cursor is visible (**IsCursorVisible** = TRUE) then **Y** is the *y* screen co-ordinate of the top-left hand pixel in the cursor image. This field is only valid if **PositionValid** is TRUE. **Y** can be negative; for example, when a hot spot in the center of cursor is placed in the top-left of the screen.

### `IsCursorShapeUpdated`

 [out] A Boolean value that indicates whether the cursor shape has been updated since the last time the driver called [**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2). If it has been updated then the OS updates the **CursorShapeInfo** structure and copies the new cursor image data into the [**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor).**pShapeBuffer** buffer.

### `CursorShapeInfo`

[out] A [**IDDCX_CURSOR_SHAPE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_cursor_shape_info) structure in which the OS copies the current cursor information if the cursor is visible. If the cursor is not visible then the OS zeroes this structure.

### `PositionValid`

[out] A Boolean value that indicates whether the **X**, **Y**, and **PositionId** fields in this structure are valid.

### `PositionId`

[out] The ID of the last cursor position that the OS received for this monitor. The driver can compare this ID to the last cursor position that it processed to know whether it should process a new position update.

Note that there are cases where the position values might not have changed but the position ID value has changed. In this case the driver should process the position as if it was a new move. **PositionId** is not updated if **IsCursorVisible** changes and is only valid if **PositionValid** is TRUE.

## See also

[**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2)