# IPreviewHandlerVisuals::SetBackgroundColor

## Description

Sets the background color of the preview handler.

## Parameters

### `color` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A value of type [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) to use for the preview handler background.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** These are suggestions. It is not compulsory for this method to be called. The preview handlers must be able to make their own decisions.