# IPicture::get_Type

## Description

Retrieves the current type of the picture contained in the picture object.

## Parameters

### `pType` [out]

Pointer to a variable that receives the picture type. The Type property can have any one of the values contained in the [PICTYPE](https://learn.microsoft.com/windows/desktop/com/pictype-constants) enumeration.

## Return value

This method supports the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The type was returned successfully. |
| **E_POINTER** | The value of *pType* is not valid. For example, it may be **NULL**. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)

[OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect)

[PICTYPE](https://learn.microsoft.com/windows/desktop/com/pictype-constants)