# IFont::put_Weight

## Description

Sets the font's Weight property.

## Parameters

### `weight` [in]

The new Weight for the font. For a list of available font weights, see the description of the **lfWeight** member of
the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The Weight property was changed successfully. |
| **S_FALSE** | This font does not support different weights. This value is not an error condition. |

## Remarks

This property may
affect the Bold property as well. The Bold
property is set to **TRUE** if the Weight property is
greater than the average of **FW_NORMAL** (400) and **FW_BOLD** (700),
that is 550.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Weight](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_weight)