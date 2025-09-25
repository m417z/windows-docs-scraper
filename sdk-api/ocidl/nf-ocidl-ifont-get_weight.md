# IFont::get_Weight

## Description

Gets the font's current Weight property.

## Parameters

### `pWeight` [out]

A pointer to the caller-allocated variable that receives the current Weight property for the font. For a list of possible values, see the **lfWeight** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
|  | The weight was retrieved successfully. If the weight is indeterminate, a font object should store **FW_NORMAL** in **pWeight* and return **S_OK**. |
|  | The address in the *pWeight* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Weight](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_weight)