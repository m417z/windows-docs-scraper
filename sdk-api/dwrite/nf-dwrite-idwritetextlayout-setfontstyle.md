# IDWriteTextLayout::SetFontStyle

## Description

 Sets the font style for text within a text range specified by a [DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range) structure.

## Parameters

### `fontStyle`

Type: **[DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style)**

The font style to be set for text within a range specified by *textRange*.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

The text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The font style can be set to Normal, Italic or Oblique. The following illustration shows three styles for the Palatino font. For more information, see [DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style).

![Illustration of normal, italic, and oblique font styles for the Palatino font](https://learn.microsoft.com/windows/win32/api/dwrite/images/FontStyle_for_Palatino.png)

#### Examples

The following code illustrates how to set the font style to italic.

```cpp

// Set the font style to italic for the entire string.
DWRITE_TEXT_RANGE textRange = {0, cTextLength_};

if (SUCCEEDED(hr))
{
    hr = pTextLayout_->SetFontStyle(DWRITE_FONT_STYLE_ITALIC, textRange);
}

```

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)