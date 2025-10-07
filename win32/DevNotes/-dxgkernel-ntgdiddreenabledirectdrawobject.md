# NtGdiDdReenableDirectDrawObject function

\[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Re-enables a Microsoft DirectDraw kernel-mode device object after a mode switch.

## Parameters

*hDirectDrawLocal* \[in\]

DirectDraw object that needs to be re-enabled.

*pubNewMode* \[in, out\]

Pointer to a BOOL that will be filled with a value that represents whether the display mode changed.

## Return value

If successful (the device can be re-enabled), this function returns **TRUE**. Otherwise (for example, the display driver was changed), it returns **FALSE**.

## Remarks

Once the object has been re-enabled, the capabilities for the device can be re-queried via a call to [**NtGdiDdQueryDirectDrawObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddquerydirectdrawobject).

Applications are advised to use the DirectDraw or [Direct3D](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference) version 8 APIs, which automate and abstract this process in a manner independent of the operating system.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdReenableDirectDrawObject**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddreenabledirectdrawobject)

