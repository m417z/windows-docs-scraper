# IDWriteTextLayout::GetDrawingEffect

## Description

 Gets the application-defined drawing effect at the specified text position.

## Parameters

### `currentPosition`

Type: **UINT32**

The position of the text whose drawing effect is to be retrieved.

### `drawingEffect` [out]

Type: **IUnknown****

When this method returns, contains an address of a pointer to the current application-defined drawing effect. Usually this effect is a foreground brush that is used in glyph drawing.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

Contains the range of text that has the same formatting as the text at the position specified by *currentPosition*. This means the run has the exact formatting as the position specified, including but not limited to the drawing effect.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)