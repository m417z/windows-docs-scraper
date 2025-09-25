# IPicture::get_Height

## Description

Retrieves the current height of the picture in the picture object.

## Parameters

### `pHeight` [out]

A pointer to a variable that receives the height.

## Return value

This method supports the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The height was returned successfully. |
| **E_POINTER** | The value of *pHeight* is not valid. For example, it may be **NULL**. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)