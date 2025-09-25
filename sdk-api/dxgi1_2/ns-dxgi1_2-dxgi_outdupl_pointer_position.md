# DXGI_OUTDUPL_POINTER_POSITION structure

## Description

The **DXGI_OUTDUPL_POINTER_POSITION** structure describes the position of the hardware cursor.

## Members

### `Position`

The position of the hardware cursor relative to the top-left of the adapter output.

### `Visible`

Specifies whether the hardware cursor is visible. **TRUE** if visible; otherwise, **FALSE**. If the hardware cursor is not visible, the calling application does not display the cursor in the client.

## Remarks

The **Position** member is valid only if the **Visible** member’s value is set to **TRUE**.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[DXGI_OUTDUPL_FRAME_INFO](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_frame_info)