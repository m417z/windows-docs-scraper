# IDWriteTextFormat::SetLineSpacing

## Description

 Sets the line spacing.

## Parameters

### `lineSpacingMethod`

Type: **[DWRITE_LINE_SPACING_METHOD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_line_spacing_method)**

Specifies how line height is being determined; see [DWRITE_LINE_SPACING_METHOD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_line_spacing_method) for more information.

### `lineSpacing`

Type: **FLOAT**

The line height, or distance between one baseline to another.

### `baseline`

Type: **FLOAT**

The distance from top of line to baseline. A reasonable ratio to *lineSpacing* is 80 percent.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 For the default method, spacing depends solely on the content.
For uniform spacing, the specified line height overrides the content.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)