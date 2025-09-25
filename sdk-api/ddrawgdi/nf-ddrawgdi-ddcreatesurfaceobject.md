# DdCreateSurfaceObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdCreateSurfaceObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddcreatesurfaceobject) function and creates a kernel-mode surface object.

**GdiEntry4** is defined as an alias for this function.

## Parameters

### `pSurfaceLocal`

Pointer to the user-mode surface object. See the DDK documentation for details. A handle to the kernel-mode object is placed in *pSurfaceLocal*->**hDDSurface**.

### `bPrimarySurface`

Reserved.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

This function is used to create objects that represent system memory surfaces. Video memory surfaces are given a kernel-mode representation as an implicit part of the [NtGdiDdCreateSurfaceObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddcreatesurfaceobject) call.

Applications are advised to use the
DirectDraw and
[Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)