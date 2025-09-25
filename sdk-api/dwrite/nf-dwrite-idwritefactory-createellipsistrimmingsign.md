# IDWriteFactory::CreateEllipsisTrimmingSign

## Description

 Creates an inline object for trimming, using an ellipsis as the omission sign.

## Parameters

### `textFormat`

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)***

A text format object, created with [CreateTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createtextformat), used for text layout.

### `trimmingSign` [out]

Type: **[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)****

When this method returns, contains an address of a pointer to the omission (that is, ellipsis trimming) sign created by this method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The ellipsis will be created using the current settings of the format, including base font, style, and any effects.
Alternate omission signs can be created by the application by implementing [IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject).

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)