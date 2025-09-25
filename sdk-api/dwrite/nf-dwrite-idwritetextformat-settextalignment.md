# IDWriteTextFormat::SetTextAlignment

## Description

Sets the alignment of text in a paragraph, relative to the leading and trailing edge of a layout box for a [IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat) interface.

## Parameters

### `textAlignment`

Type: **[DWRITE_TEXT_ALIGNMENT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_text_alignment)**

The text alignment option being set for the paragraph of type DWRITE_TEXT_ALIGNMENT. For more information, see Remarks.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The textAlignment argument is invalid. |

## Remarks

The text can be aligned to the leading or trailing edge of the layout box, or it can be centered. The following illustration shows text with the alignment set to [DWRITE_TEXT_ALIGNMENT_LEADING](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_text_alignment), **DWRITE_TEXT_ALIGNMENT_CENTER**, and **DWRITE_TEXT_ALIGNMENT_TRAILING**, respectively.

![Illustration of text paragraphs with leading, centered, and trailing alignment](https://learn.microsoft.com/windows/win32/api/dwrite/images/TextAlignment.png)

**Note** The alignment is dependent on reading direction, the above is for left-to-right reading direction. For right-to-left reading direction it would be the opposite.

See [DWRITE_TEXT_ALIGNMENT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_text_alignment) for more information.

#### Examples

```cpp
if (SUCCEEDED(hr))
{
    hr = pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
}

```

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)