# IPicture::SelectPicture

## Description

Selects a bitmap picture into a given device context, and returns the device context in which the picture was previously selected as well as the picture's GDI handle. This method works in conjunction with [IPicture::get_CurDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-get_curdc).

## Parameters

### `hDCIn` [in]

A handle for the device context in which to select the picture.

### `phDCOut` [out]

A pointer to a variable that receives the previous device context. This parameter can be **NULL** if the caller does not need this information. Ownership of the device context is always the responsibility of the caller.

### `phBmpOut` [out]

A pointer to a variable that receives the GDI handle of the picture. This parameter can be **NULL** if the caller does not need the handle. Ownership of this handle is determined by the *fOwn* parameter passed to [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect). Pictures loaded from a stream always own their resources.

## Return value

This method supports the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)

[IPicture::get_CurDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-get_curdc)