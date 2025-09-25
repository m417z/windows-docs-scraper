# IDWriteTextLayout2::GetMetrics

## Description

 Retrieves overall metrics for the formatted string.

## Parameters

### `textMetrics` [out]

Type: **[DWRITE_TEXT_METRICS1](https://learn.microsoft.com/windows/win32/api/dwrite_2/ns-dwrite_2-dwrite_text_metrics1)***

When this method returns, contains the measured distances of text and associated content after being formatted.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextlayout2)