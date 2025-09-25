# IFont::put_Italic

## Description

Sets the font's Italic property.

## Parameters

### `italic` [in]

The new Italic property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The italic state was changed successfully. |
| **S_FALSE** | The font does not support an italic state. This value is not an error condition. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Italic](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_italic)