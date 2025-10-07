# NtGdiDdSetGammaRamp function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Sets the gamma ramp for the device.

## Parameters

*hDirectDraw* \[in\]

Handle to the kernel-mode driver object for which the ramp is to be set.

*hdc* \[in\]

Reserved.

*lpGammaRamp* \[in\]

Pointer to an array of **DDGAMMARAMP** structures.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **NULL**.

## Remarks

It is recommended that applications use the **IDirectDrawGammaControl::SetGammaRamp** or [**IDirect3DDevice9::SetGammaRamp**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setgammaramp) methods instead because these methods offer the same functionality independent of the operating system.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

