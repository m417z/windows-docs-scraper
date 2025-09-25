# IFont::get_Size

## Description

Retrieves the point size of the font.

## Parameters

### `pSize` [out]

 A pointer to the caller-allocated variable that receives the size, in **HIMETRIC**
units.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the
following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The size was retrieved successfully. |
| **E_POINTER** | The address in the *pSize* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_size)