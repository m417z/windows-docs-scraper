# IDirect3DDevice9::ShowCursor

## Description

Displays or hides the cursor.

## Parameters

### `bShow` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If bShow is **TRUE**, the cursor is shown. If bShow is **FALSE**, the cursor is hidden.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value indicating whether the cursor was previously visible. **TRUE** if the cursor was previously visible, or **FALSE** if the cursor was not previously visible.

## Remarks

Direct3D cursor functions use either GDI cursor or software emulation, depending on the hardware. Users usually want to respond to a WM_SETCURSOR message. For example, the users might want to write the message handler like this:

```

case WM_SETCURSOR:

// Turn off window cursor

SetCursor( NULL );

m_pd3dDevice->ShowCursor( TRUE );

return TRUE; // prevent Windows from setting cursor to window class cursor

break;

```

Or users might want to call the [IDirect3DDevice9::SetCursorProperties](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorproperties) method if they want to change the cursor. See the code in the DirectX Graphics C/C++ Samples for more detail.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetCursorPosition](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorposition)

[IDirect3DDevice9::SetCursorProperties](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorproperties)