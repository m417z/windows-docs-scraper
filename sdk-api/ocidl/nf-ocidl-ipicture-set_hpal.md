# IPicture::set_hPal

## Description

Assigns a GDI palette to the picture contained in the picture object.

## Parameters

### `hPal` [in]

A handle to the GDI palette assigned to the picture.

## Return value

This method supports the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

### Notes to Implementers

Ownership of the palette passed to this method depends on how the picture object was created, as specified by the *fOwn* parameter to [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect). [OleLoadPicture](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-oleloadpicture) forces *fOwn* to **TRUE**; if the object owns the picture, then it takes over ownership of this palette.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)