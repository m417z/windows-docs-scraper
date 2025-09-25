# IDirect3DDevice9::SetCursorProperties

## Description

Sets properties for the cursor.

## Parameters

### `XHotSpot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

X-coordinate offset (in pixels) that marks the center of the cursor. The offset is relative to the upper-left corner of the cursor. When the cursor is given a new position, the image is drawn at an offset from this new position determined by subtracting the hot spot coordinates from the position.

### `YHotSpot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Y-coordinate offset (in pixels) that marks the center of the cursor. The offset is relative to the upper-left corner of the cursor. When the cursor is given a new position, the image is drawn at an offset from this new position determined by subtracting the hot spot coordinates from the position.

### `pCursorBitmap` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. This parameter must point to an 8888 ARGB surface (format D3DFMT_A8R8G8B8). The contents of this surface will be copied and potentially format-converted into an internal buffer from which the cursor is displayed. The dimensions of this surface must be less than the dimensions of the display mode, and must be a power of two in each direction, although not necessarily the same power of two. The alpha channel must be either 0.0 or 1.0.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

An operating system cursor is created and used under either of these conditions:

* The hardware has set D3DCURSORCAPS_COLOR (see [D3DCURSORCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcursorcaps)), and the cursor size is 32x32 (which is the cursor size in the operating system).
* The application is running in windowed mode.

Otherwise, DirectX uses an emulated cursor. An application uses [IDirect3DDevice9::SetCursorPosition](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorposition) to move an emulated cursor to follow mouse movement.

It is recommended for applications to always trap WM_MOUSEMOVE events and call DXSetCursorPosition.

Direct3D cursor functions use either GDI cursor or software emulation, depending on the hardware. Users typically want to respond to a WM_SETCURSOR message. For example, they might want to write the message handler as follows:

```

case WM_SETCURSOR:
// Turn off window cursor.
SetCursor( NULL );
m_pd3dDevice->ShowCursor( TRUE );
return TRUE; // Prevent Windows from setting cursor to window class cursor.
break;

```

Or, users might want to call the **IDirect3DDevice9::SetCursorProperties** method if they want to change the cursor.

The application can determine what hardware support is available for cursors by examining appropriate members of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure. Typically, hardware supports only 32x32 cursors and, when windowed, the system might support only 32x32 cursors. In this case, **IDirect3DDevice9::SetCursorProperties** still succeeds but the cursor might be reduced to that size. The hot spot is scaled appropriately.

The cursor does not survive when the device is lost. This method must be called after the device is reset.

## See also

[D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::ShowCursor](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-showcursor)