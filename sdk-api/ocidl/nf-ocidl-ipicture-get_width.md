# IPicture::get_Width

## Description

Retrieves the current width of the picture in the picture object.

## Parameters

### `pWidth` [out]

A pointer to a variable that receives the width.

## Return value

This method supports the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The width was returned successfully. |
| **E_POINTER** | The value of *pWidth* is not valid. For example, it may be **NULL**. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)