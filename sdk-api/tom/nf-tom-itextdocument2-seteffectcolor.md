# ITextDocument2::SetEffectColor

## Description

Specifies the color to use for special text attributes.

## Parameters

### `Index` [in]

Type: **long**

The index of the color to retrieve. For a list of values, see [GetEffectColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-geteffectcolor).

### `Value` [in]

Type: **long**

The new color for the specified index.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The first 16 index values are for special underline colors. If an index between 1 and 16 hasn't been defined by a call to the **ITextDocument2:SetEffectColor** method, the corresponding Microsoft Word default color is used.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetEffectColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-geteffectcolor)