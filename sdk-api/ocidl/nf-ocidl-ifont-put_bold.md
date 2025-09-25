# IFont::put_Bold

## Description

Sets the font's Bold property.

## Parameters

### `bold` [in]

The new Bold property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The bold state was changed successfully. |
| **S_FALSE** | The font does not support a bold state. Note that this is not an error condition. |

## Remarks

Changing the
Bold property may also change the Weight
property. Setting the Bold property to **TRUE** sets the
Weight property to **FW_BOLD** (700); setting the
Bold property to **FALSE** sets the
Weight property to **FW_NORMAL** (400).

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Bold](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_bold)