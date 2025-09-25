# IDWriteTextLayout::SetInlineObject

## Description

 Sets the inline object.

## Parameters

### `inlineObject`

Type: **[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)***

An application-defined inline object.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The application may call this function to specify the set of properties describing an application-defined inline object for specific range.

 This inline object applies to the specified range and will be passed back
to the application by way of the [DrawInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextrenderer-drawinlineobject) callback when the range is drawn.
Any text in that range will be suppressed.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)