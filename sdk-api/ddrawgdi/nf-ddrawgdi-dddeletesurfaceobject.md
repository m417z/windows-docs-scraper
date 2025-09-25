# DdDeleteSurfaceObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdDeleteSurfaceObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdidddeletesurfaceobject) function and deletes a kernel-mode surface object previously created by [NtGdiDdCreateSurfaceObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddcreatesurfaceobject).

**GdiEntry5** is defined as an alias for this function.

## Parameters

### `pSurfaceLocal`

Pointer to the user-mode surface object that has a valid **hDDSurface**. See the DDK documentation for details.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications are advised to use the
DirectDraw and
[Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## See also

[DdCreateSurfaceObject](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddcreatesurfaceobject)

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)