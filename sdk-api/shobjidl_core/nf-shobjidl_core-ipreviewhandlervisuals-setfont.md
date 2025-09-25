# IPreviewHandlerVisuals::SetFont

## Description

Sets the font attributes to be used for text within the preview handler.

## Parameters

### `plf` [in]

Type: **const LOGFONTW***

A pointer to a [LOGFONTW Structure](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa741231(v=vs.85)) containing the necessary attributes for the font to use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** These are suggestions. It is not compulsory for this method to be called. The preview handlers must be able to make their own decisions.