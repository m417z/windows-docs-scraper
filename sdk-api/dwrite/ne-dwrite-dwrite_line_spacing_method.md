## Description

The method used for line spacing in a text layout.

## Constants

### `DWRITE_LINE_SPACING_METHOD_DEFAULT`

Line spacing depends solely on the content, adjusting to accommodate the size of fonts and inline objects.

### `DWRITE_LINE_SPACING_METHOD_UNIFORM`

Lines are explicitly set to uniform spacing, regardless of the size of fonts and inline objects. This can be useful to avoid the uneven appearance that can occur from font fallback.

### `DWRITE_LINE_SPACING_METHOD_PROPORTIONAL`

Line spacing and baseline distances are proportional to the computed values based on the content, the size of the fonts and inline objects.

> [!NOTE]
> This value is available only on Windows 10 or later, and it can be used with [IDWriteTextLayout3::SetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritetextlayout3-setlinespacing), but it can't be used with [IDWriteTextFormat::SetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-setlinespacing).

## Remarks

The line spacing method is set by using the [SetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-setlinespacing) method of the [IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat) or [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) interfaces. To get the current line spacing method of a text format or text layout use the [GetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-getlinespacing).

## See also

[GetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-getlinespacing)

[SetLineSpacing](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-setlinespacing)