# DCICreatePrimary function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Creates a primary surface and obtains surface information.

## Parameters

### `hdc` [in]

The device context handle of the device for the primary surface to be created.

### `lplpSurface` [out]

A pointer to a **DCISURFACEINFO** structure.

## Return value

If the function succeeds, DCI_OK is returned. Otherwise, it returns one of the DCI errors.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)