# NtGdiDdDeleteSurfaceObject function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

**NtGdiDdDeleteSurfaceObject** deletes a previously created kernel-mode surface object.

## Parameters

*hSurface* \[in\]

Handle to the previously created kernel-mode surface object.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications are advised to use the DirectDraw and [Direct3D](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdDeleteSurfaceObject**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-dddeletesurfaceobject)

[**NtGdiDdCreateSurfaceObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatesurfaceobject)

