# DCIBeginAccess function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Obtains an access pointer to display frame buffer based on the given rectangle.

## Parameters

### `pdci` [in]

A pointer to a **DCISURFACEINFO** structure.

### `x` [in]

The x-coordinate of the upper-left corner of the rectangle.

### `y` [in]

The y-coordinate of the upper-left corner of the rectangle.

### `dx` [in]

The width of the rectangle.

### `dy` [in]

The height of the rectangle.

## Return value

If the function succeeds, the return value is DCI_OK or DCI_STATUS_POINTERCHANGED. DCI_STATUS_POINTERCHANGED indicates that the virtual address of the frame buffer could have been changed since the last call. So the application should not assume the consistency of the virtual address of the display frame buffer. If the function fails, the return value is one of the DCI errors.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)