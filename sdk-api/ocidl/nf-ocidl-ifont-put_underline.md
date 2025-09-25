# IFont::put_Underline

## Description

Sets the font's Underline property.

## Parameters

### `underline` [in]

The new Underline property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The underline state was changed successfully. |
| **S_FALSE** | The font does not support an underline state. This value is not an error condition. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Underline](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_underline)