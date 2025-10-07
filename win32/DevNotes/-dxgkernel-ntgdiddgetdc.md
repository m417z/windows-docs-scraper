# NtGdiDdGetDC function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Creates a device context (DC) for the specified surface.

## Parameters

*hSurface* \[in\]

Handle to a kernel-mode DirectDraw surface previously returned by [**NtGdiDdCreateSurface**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurface) or [**NtGdiDdCreateSurfaceObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurfaceobject).

*puColorTable* \[in\]

Pointer to an override color table for the returned DC.

## Return value

If successful, this function returns a valid **HDC**; otherwise it returns **NULL**.

## Remarks

Only one DC is allowed per surface at any given time. Subsequent calls to **NtGdiDdGetDC** will fail until the previous DC is released.

Applications are advised to call [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/win32/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc) instead, which provides the same functionality in a manner independent of the operating system.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdGetDC**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddgetdc)

