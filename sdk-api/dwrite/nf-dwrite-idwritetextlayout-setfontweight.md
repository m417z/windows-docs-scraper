# IDWriteTextLayout::SetFontWeight

## Description

 Sets the font weight for text within a text range specified by a [DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range) structure.

## Parameters

### `fontWeight`

Type: **[DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight)**

The font weight to be set for text within the range specified by *textRange*.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The font weight can be set to one of the predefined font weight values provided in the [DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight) enumeration or an integer from 1 to 999. Values outside this range will cause the method to fail with an **E_INVALIDARG** return value.

The following illustration shows an example of Normal and UltraBold weights for the Palatino Linotype typeface.

![Illustration of the letter "W" in Normal and UltraBold weights](https://learn.microsoft.com/windows/win32/api/dwrite/images/FontWeight_for_Palatino.png)

#### Examples

The following code illustrates how to set the font weight to bold.

```cpp

// Set the font weight to bold for the entire string.
DWRITE_TEXT_RANGE textRange = {0, cTextLength_};

if (SUCCEEDED(hr))
{
    hr = pTextLayout_->SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, textRange);
}

```

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)