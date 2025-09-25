# IPreviewHandlerVisuals::SetTextColor

## Description

Sets the color of the text within the preview handler.

## Parameters

### `color` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A value of type [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) to use for the preview handler text color.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** These are suggestions. It is not compulsory for this method to be called; the preview handlers must be able to make their own decisions.