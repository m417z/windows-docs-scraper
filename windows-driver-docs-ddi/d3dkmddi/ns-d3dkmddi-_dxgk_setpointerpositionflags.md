# DXGK_SETPOINTERPOSITIONFLAGS structure

## Description

The **DXGK_SETPOINTERPOSITIONFLAGS** structure identifies, in bit-field flags, information about a mouse pointer.

## Members

### `Visible` [in]

A **UINT** value that specifies whether the mouse pointer is visible. If this member is set, the mouse pointer is visible; if this member is not set, the mouse pointer is invisible. The driver should ignore the values in the **X** and **Y** members of the [**DXGKARG_SETPOINTERPOSITION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointerposition) structure if **Visible** is not set (that is, **Visible** is set to 0).

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Procedural` [in]

A **UINT** value that specifies whether the mouse pointer position was set by an application with the [**SetCursorPos**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setcursorpos) or similar cursor function instead of coming from user device input.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

Supported starting with Windows 8.

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that **DXGK_SETPOINTERPOSITIONFLAGS** contains that can hold one 32-bit value that indicates information about a mouse pointer.

## See also

[**DXGKARG_SETPOINTERPOSITION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setpointerposition)