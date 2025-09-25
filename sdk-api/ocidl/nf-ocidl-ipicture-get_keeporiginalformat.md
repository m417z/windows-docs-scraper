# IPicture::get_KeepOriginalFormat

## Description

Retrieves the current value of the picture's KeepOriginalFormat property.

## Parameters

### `pKeep` [out]

A pointer to a variable that receives the value of the property.

## Return value

This method supports the standard return value E_FAIL, as well as the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The value of the KeepOriginalFormat property was returned successfully. |
| **E_POINTER** | The value of *pKeep* is not valid. For example, it may be **NULL**. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)

[IPicture::put_KeepOriginalFormat](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-put_keeporiginalformat)