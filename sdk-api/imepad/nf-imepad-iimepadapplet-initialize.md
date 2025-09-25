# IImePadApplet::Initialize

## Description

Called from [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) interface to initialize [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet).

## Parameters

### `lpIImePad`

Pointer to [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) (**IUnknown** *)

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## Remarks

When the ImePad user interface is created, [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) calls this method and sets the IImePad interface pointer as an argument. The applet can save and use this pointer to call the [pIImePad->IImePad::Request](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepad-request) method.

## See also

[IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet)