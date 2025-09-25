# IDirect3DDevice9::SetDialogBoxMode

## Description

This method allows the use of GDI dialog boxes in full-screen mode applications.

## Parameters

### `bEnableDialogs` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to enable GDI dialog boxes, and **FALSE** to disable them.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL unless all of the following are true.

* The application specified a back buffer format compatible with GDI, in other words, one of D3DFMT_X1R5G5B5, D3DFMT_R5G6B5, or D3DFMT_X8R8G8B8.
* The application specified no multisampling.
* The application specified D3DSWAPEFFECT_DISCARD.
* The application specified D3DPRESENTFLAG_LOCKABLE_BACKBUFFER.
* The application did not specify D3DCREATE_ADAPTERGROUP_DEVICE.
* The application is not between BeginScene and EndScene.

## Remarks

The GDI dialog boxes must be created as child to the device window. They should also be created within the same thread that created the device because this enables the parent window to manage redrawing the child window.

The method has no effect for windowed mode applications, but this setting will be respected if the application resets the device into full-screen mode. If SetDialogBoxMode succeeds in a windowed mode application, any subsequent reset to full-screen mode will be checked against the restrictions listed above. Also, SetDialogBoxMode causes all back buffers on the swap chain to be discarded, so an application is expected to refresh its content for all back buffers after this call.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)