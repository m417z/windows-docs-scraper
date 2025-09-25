# IDXGISurface1::ReleaseDC

## Description

Releases the GDI device context (DC) that is associated with the current surface and allows you to use Direct3D to render.

## Parameters

### `pDirtyRect` [in, optional]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a **RECT** structure that identifies the dirty region of the surface.
A dirty region is any part of the surface that you used for GDI rendering and that you want to preserve.
This area is used as a performance hint to graphics subsystem in certain scenarios.
Do not use this parameter to restrict rendering to the specified rectangular region.
If you pass in **NULL**, **ReleaseDC** considers the whole surface as dirty.
Otherwise, **ReleaseDC** uses the area specified by the RECT as a performance hint to indicate what areas have been manipulated by GDI rendering.

You can pass a pointer to an empty **RECT** structure (a rectangle with no position or area) if you didn't change any content.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

Use the **ReleaseDC** method to release the DC and indicate that your application finished all GDI rendering to this surface.
You must call the **ReleaseDC** method before you can use Direct3D to perform additional rendering.

Prior to resizing buffers you must release all outstanding DCs.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGISurface1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface1)