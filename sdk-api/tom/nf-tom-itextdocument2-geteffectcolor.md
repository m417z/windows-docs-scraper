# ITextDocument2::GetEffectColor

## Description

Retrieves the color used for special text attributes.

## Parameters

### `Index` [in]

Type: **long**

The index of the color to retrieve. It can be one of the following values.

| Index | Meaning |
| --- | --- |
| 0 | Text color. |
| 1 | RGB(0, 0, 0) |
| 2 | RGB(0, 0, 255) |
| 3 | RGB(0, 255, 255) |
| 4 | RGB(0, 255, 0) |
| 5 | RGB(255, 0, 255) |
| 6 | RGB(255, 0, 0) |
| 7 | RGB(255, 255, 0) |
| 8 | RGB(255, 255, 255) |
| 9 | RGB(0, 0, 128) |
| 10 | RGB(0, 128, 128) |
| 11 | RGB(0, 128, 0) |
| 12 | RGB(128, 0, 128) |
| 13 | RGB(128, 0, 0) |
| 14 | RGB(128, 128, 0) |
| 15 | RGB(128, 128, 128) |
| 16 | RGB(192, 192, 192) |

### `pValue` [out]

Type: **long***

The color that corresponds to the specified index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The first 16 index values are for special underline colors. If an index between 1 and 16 hasn't been defined by a call to the [ITextDocument2:SetEffectColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-seteffectcolor) method, **GetEffectColor** returns the corresponding Microsoft Word default color.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetEffectColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-seteffectcolor)