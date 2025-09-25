# DCICloseProvider function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Closes a device context of a display.

## Parameters

### `hdc` [in]

The device context handle to be closed. The handle was created with [DCIOpenProvider](https://learn.microsoft.com/windows/desktop/api/dciman/nf-dciman-dciopenprovider).

## Return value

If the function succeeds, the return value is nonzero. Otherwise, it returns zero.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)