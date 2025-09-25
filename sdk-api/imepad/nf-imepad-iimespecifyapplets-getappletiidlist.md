# IImeSpecifyApplets::GetAppletIIDList

## Description

Called from the [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) interface to enumerate the [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) interfaces that are implemented.

## Parameters

### `refiid` [in]

IID of the [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) interface. This IID is defined in Imepad.h as **IID_IImePadApplet**. This is for **IImePadApplet**'s future enhancement

### `lpIIDList` [in, out]

Pointer to a APPLETIIDLIST structure. Sets the applet's IID list and count.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## See also

[IImeSpecifyApplets](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimespecifyapplets)