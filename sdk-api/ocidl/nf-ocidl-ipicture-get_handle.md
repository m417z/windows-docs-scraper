# IPicture::get_Handle

## Description

Retrieves the handle to the picture managed within this picture object to a specified location.

## Parameters

### `pHandle` [out]

A pointer to a variable that receives the handle. The caller is responsible for this handle upon successful return. The variable is set to **NULL** on failure.

## Return value

This method supports the standard return values E_FAIL and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The handle was returned successfully. |
| **E_POINTER** | The value of *phandle* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

The picture object may retain ownership of the picture. However, the caller can be assured that the picture will remain valid until either the caller specifically destroys the picture or the picture object is itself destroyed. The *fOwn* parameter to [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect) determines ownership when the picture object is created. [OleLoadPicture](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-oleloadpicture) forces *fOwn* to **TRUE**.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)