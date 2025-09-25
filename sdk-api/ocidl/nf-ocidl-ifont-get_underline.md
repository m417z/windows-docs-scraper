# IFont::get_Underline

## Description

Gets the font's current Underline property..

## Parameters

### `pUnderline` [out]

A pointer to the caller-allocated variable that receives the current Underline property for the font.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The state was retrieved successfully. If the state is indeterminate, a font object should set         **pUnderline* to **FALSE** and return **S_OK**. |
| **E_POINTER** | The address in the *pUnderline* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Underline](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_underline)