# IImePadApplet::CreateUI

## Description

Called from [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) to get the applet's window handle, style, and size.

The applet can set its window style and sizing policy.

## Parameters

### `hwndParent` [in]

Window handle of the [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) GUI. The applet can create the window as its child window.

### `lpImeAppletUI` [in]

Pointer to [IMEAPPLETUI](https://learn.microsoft.com/windows/desktop/api/imepad/ns-imepad-imeappletui) structure. The applet can set its window style.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## See also

[IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet)