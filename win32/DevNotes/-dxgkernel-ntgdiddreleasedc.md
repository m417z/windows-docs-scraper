# NtGdiDdReleaseDC function

\[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Releases the previously created device context (DC) for the indicated kernel-mode Microsoft DirectDraw surface object.

## Parameters

*hSurface* \[in\]

Handle to the previously created kernel-mode DirectDraw surface object.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications that need to obtain a DC for a DirectDraw surface may use [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/win32/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc), which exposes this functionality in a manner independent of the operating system.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdReleaseDC**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddreleasedc)

