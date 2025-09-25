# IFont::put_Size

## Description

Sets the point size of the font.

## Parameters

### `size` [in]

The new size of the font, in **HIMETRIC** units.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The font was resized successfully. |
| **E_POINTER** | The value of the *size* parameter is not valid. For example, it does not contain a usable font size. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_size)