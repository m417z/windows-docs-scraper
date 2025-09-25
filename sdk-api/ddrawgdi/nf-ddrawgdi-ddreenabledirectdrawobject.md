# DdReenableDirectDrawObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdReenableDirectDrawObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddreenabledirectdrawobject) function. It re-enables a Microsoft DirectDraw driver instance after a mode switch-style event such as a true mode switch, appearance of a full-screen Microsoft MS-DOS box, or change of display driver.

**GdiEntry10** is defined as an alias for this function.

## Parameters

### `pDirectDrawGlobal`

DirectDraw object that needs to be re-enabled.

### `pbNewMode`

Pointer to a BOOL that will be filled with a value that represents whether the display mode changed.

## Return value

If successful (the device can be re-enabled), this function returns **TRUE**. Otherwise (for example, the display driver was changed), it returns **FALSE**.

## Remarks

Once the object has been re-enabled, the capabilities for the device can be re-queried using a call to [DdQueryDirectDrawObject](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddquerydirectdrawobject) or GdiEntry2.

Applications are advised to use the
DirectDraw or [Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs, which automate and abstract this process in a manner independent of the operating system.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)