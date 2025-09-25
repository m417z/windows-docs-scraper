# DdSetGammaRamp function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

The **DdSetGammaRamp** function sets the gamma ramp for the device.

**GdiEntry15** is defined as an alias for this function.

## Parameters

### `pDDraw` [in]

Pointer to user-mode DirectDraw device object.

### `hdc` [in]

Reserved.

### `lpGammaRamp` [in]

Pointer to an array of **DDGAMMARAMP** structures.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **NULL**.

## Remarks

It is recommended that applications use the **IDirectDrawGammaControl::SetGammaRamp** or **IDirect3DDevice9::SetGammaRamp** methods instead since these methods offer the same functionality independent of the operating system.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)