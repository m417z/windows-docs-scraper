# IDirect3DDevice9::SetCursorPosition

## Description

Sets the cursor position and update options.

## Parameters

### `X` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new X-position of the cursor in virtual desktop coordinates. See Remarks.

### `Y` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new Y-position of the cursor in virtual desktop coordinates. See Remarks.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the update options for the cursor. Currently, only one flag is defined.

| Value | Meaning |
| --- | --- |
| **D3DCURSOR_IMMEDIATE_UPDATE** | Update cursor at the refresh rate.<br><br>If this flag is specified, the system guarantees that the cursor will be updated at a minimum of half the display refresh rate, but never more frequently than the display refresh rate. Otherwise, the method delays cursor updates until the next [IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) call. Not setting this flag usually results in better performance than if the flag is set. However, applications should set this flag if the rate of calls to Present is low enough that users would notice a significant delay in cursor motion. This flag has no effect in a windowed-mode application. Some video cards implement hardware color cursors. This flag does not have an effect on these cards. |

## Remarks

When running in full-screen mode, screen space coordinates are the back buffer coordinates appropriately scaled to the current display mode. When running in windowed mode, screen space coordinates are the desktop coordinates. The cursor image is drawn at the specified position minus the hotspot-offset specified by the [SetCursorProperties](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorproperties) method.

If the cursor has been hidden by [ShowCursor](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-showcursor), the cursor is not drawn.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[SetCursorProperties](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcursorproperties)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-showcursor)