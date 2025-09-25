# DXGI_OUTDUPL_POINTER_SHAPE_INFO structure

## Description

The **DXGI_OUTDUPL_POINTER_SHAPE_INFO** structure describes information about the cursor shape.

## Members

### `Type`

A [DXGI_OUTDUPL_POINTER_SHAPE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_outdupl_pointer_shape_type)-typed value that specifies the type of cursor shape.

### `Width`

The width in pixels of the mouse cursor.

### `Height`

The height in scan lines of the mouse cursor.

### `Pitch`

The width in bytes of the mouse cursor.

### `HotSpot`

The position of the cursor's hot spot relative to its upper-left pixel. An application does not use the hot spot when it determines where to draw the cursor shape.

## Remarks

An application draws the cursor shape with the top-left-hand corner drawn at the position that the **Position** member of the [DXGI_OUTDUPL_POINTER_POSITION](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_pointer_position) structure specifies; the application does not use the hot spot to draw the cursor shape.

An application calls the [IDXGIOutputDuplication::GetFramePointerShape](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getframepointershape) method to retrieve cursor shape information in a **DXGI_OUTDUPL_POINTER_SHAPE_INFO** structure.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGIOutputDuplication::GetFramePointerShape](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getframepointershape)