# IDDCX_CURSOR_SHAPE_INFO structure

## Description

The **IDDCX_CURSOR_SHAPE_INFO** structure describes cursor shape.

## Members

### `Size`

Total size of this structure, in bytes.

### `ShapeId`

Unique ID for the current cursor image. **ShapeId** is incremented each time a cursor image is set, even if that image has been set before. The ID is used to check whether the current cursor image the driver has cached has changed and cannot be used in any way to allow caching for animated cursor sequences.

### `CursorType`

A [**IDDCX_CURSOR_SHAPE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_cursor_shape_type) value that indicates the type of cursor data written to the cursor shape buffer.

### `Width`

Width in pixels of the cursor shape written to the shape buffer.

### `Height`

Height in pixels of the cursor shape written to the shape buffer.

### `Pitch`

Pitch in bytes of the cursor shape written to the shape buffer.

### `XHot`

 X position of the cursor hotspot relative to the top-left of the cursor.

### `YHot`

Y position of the cursor hotspot relative to the top-left of the cursor.

## See also

[**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor)

[**IDDCX_CURSOR_SHAPE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_cursor_shape_type)