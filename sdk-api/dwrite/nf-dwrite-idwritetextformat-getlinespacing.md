# IDWriteTextFormat::GetLineSpacing

## Description

 Gets the line spacing adjustment set for a multiline text paragraph.

## Parameters

### `lineSpacingMethod` [out]

Type: **[DWRITE_LINE_SPACING_METHOD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_line_spacing_method)***

A value that indicates how line height is determined.

### `lineSpacing` [out]

Type: **FLOAT***

When this method returns, contains the line height, or distance between one baseline to another.

### `baseline` [out]

Type: **FLOAT***

When this method returns, contains the distance from top of line to baseline. A reasonable ratio to *lineSpacing* is 80 percent.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)