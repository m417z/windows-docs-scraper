# IDWriteTextFormat::SetTrimming

## Description

 Sets trimming options for text overflowing the layout width.

## Parameters

### `trimmingOptions` [in]

Type: **const [DWRITE_TRIMMING](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_trimming)***

Text trimming options.

### `trimmingSign`

Type: **[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)***

Application-defined omission sign. This parameter may be **NULL**. See [IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject) for more information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)