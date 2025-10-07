# NtGdiDdGetDxHandle function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Returns the kernel-mode Microsoft DirectX API handle to use in subsequent calls to the kernel-mode entry points that control the DirectX API mechanism.

## Parameters

*hDirectDraw* \[in\]

Handle to DirectDraw object owning the surface. This parameter is optional and may be set to **NULL**.

*hSurface* \[in\]

Handle to surface for which to return a kernel-mode DirectX API handle. This parameter is optional and may be set to **NULL**.

*bRelease* \[in\]

Set to **TRUE** if the DirectX API kernel mode interface should be released. Otherwise, **FALSE**.

## Return value

A DirectX API handle used in subsequent DirectX API-oriented kernel entry points.

## Remarks

If both *hDirectDraw* and *hSurface* are specified, *hSurface* is ignored.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

