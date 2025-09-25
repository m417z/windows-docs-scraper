# IFont::get_Bold

## Description

Gets the font's current Bold property.

## Parameters

### `pBold` [out]

A pointer to a caller-allocated
variable that receives the current Bold property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The state was retrieved successfully. If the state is indeterminate, a font object should set **pBold* to **FALSE** and return **S_OK**. |
| **E_POINTER** | The address in pBold is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Bold](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_bold)