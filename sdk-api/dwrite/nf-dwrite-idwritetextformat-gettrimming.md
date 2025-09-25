# IDWriteTextFormat::GetTrimming

## Description

 Gets the trimming options for text that overflows the layout box.

## Parameters

### `trimmingOptions` [out]

Type: **[DWRITE_TRIMMING](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_trimming)***

When this method returns, it contains a pointer to a [DWRITE_TRIMMING](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_trimming) structure that holds the text trimming options for the overflowing text.

### `trimmingSign` [out]

Type: **[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)****

When this method returns, contains an address of a pointer to a trimming omission sign. This parameter may be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)