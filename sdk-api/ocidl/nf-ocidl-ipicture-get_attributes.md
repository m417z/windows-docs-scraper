# IPicture::get_Attributes

## Description

Retrieves the current set of the picture's bit attributes.

## Parameters

### `pDwAttr` [out]

A pointer to a variable that receives the value of the Attributes property.

The Attributes property can contain any combination of the values from the [PICTUREATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-pictureattributes) enumeration.

## Return value

This method supports the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute bits were returned successfully. |
| **E_POINTER** | The value of *pdwAttr* is not valid. For example, it may be **NULL**. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)

[PICTUREATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-pictureattributes)