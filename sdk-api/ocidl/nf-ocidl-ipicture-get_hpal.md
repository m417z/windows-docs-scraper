# IPicture::get_hPal

## Description

Retrieves a copy of the palette currently used by the picture object.

## Parameters

### `phPal` [out]

A pointer to a variable that receives the palette handle. The variable is set to **NULL** on failure.

## Return value

This method supports the standard return values E_FAIL and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The height was returned successfully. |
| **S_FALSE** | This picture has no palette. The variable that *phpal* points to was set to **NULL**. |
| **E_POINTER** | The value of *phPal* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

If the picture object has ownership of the picture, it also has ownership of the palette and will destroy it when the object is itself destroyed. Otherwise the caller owns the palette. The *fOwn* parameter to [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect) determines ownership. [OleLoadPicture](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-oleloadpicture) sets *fOwn* to **TRUE** to indicate that the picture object owns the palette.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)