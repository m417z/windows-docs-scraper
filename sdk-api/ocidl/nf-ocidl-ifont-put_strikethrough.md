# IFont::put_Strikethrough

## Description

Sets the font's Strikethrough property.

## Parameters

### `strikethrough` [in]

The new Strikethrough property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The Strikethrough property was changed successfully. |
| **S_FALSE** | The font does not support a strikethrough state. This value is not an error condition. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Strikethrough](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_strikethrough)