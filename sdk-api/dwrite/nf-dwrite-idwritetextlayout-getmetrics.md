# IDWriteTextLayout::GetMetrics

## Description

 Retrieves overall metrics for the formatted string.

## Parameters

### `textMetrics` [out]

Type: **[DWRITE_TEXT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_metrics)***

When this method returns, contains the measured distances of text and associated content after being formatted.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)