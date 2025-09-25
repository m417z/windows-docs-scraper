# IFont::IsEqual

## Description

Compares this font object to another for equivalence.

## Parameters

### `pFontOther` [in]

A pointer to the [IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont) interface on the font object to be compared to this font. The reference count of the object referred to by this pointer is not affected by the comparison operation.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the
following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The two fonts are equivalent. |
| **S_FALSE** | The two fonts are not equivalent. |
| **E_POINTER** | The address in the *pFontOther* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)