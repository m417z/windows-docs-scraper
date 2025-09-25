# DdCreateDirectDrawObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdCreateDirectDrawObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddcreatedirectdrawobject) function and creates a kernel-side representation of the Microsoft DirectDraw object. A handle to this representation will be stored in *pDirectDrawGlobal*->hDD.

**GdiEntry1** is defined as an alias for this function.

## Parameters

### `pDirectDrawGlobal`

Pointer to the user-mode DirectDraw object. See DDK documentation for details.

### `hdc`

Handle to the DC for the device for which this representation is created. If 0, device will be the "display" device. Note that this function retains only one "display" DirectDraw object, and it will return a copied handle to that same object if subsequently called with *hdc* = 0.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications are advised to use the
DirectDraw and
[Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)