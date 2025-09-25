# DdDeleteDirectDrawObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdDeleteDirectDrawObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdidddeletedirectdrawobject) function and deletes a kernel-mode Microsoft DirectDraw object that was previously created using [DdCreateDirectDrawObject](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddcreatedirectdrawobject).

**GdiEntry3** is defined as an alias for this function.

## Parameters

### `pDirectDrawGlobal`

Pointer to the user-mode DirectDraw object. See the DDK documentation for details.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications are advised to use the
DirectDraw and
[Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)