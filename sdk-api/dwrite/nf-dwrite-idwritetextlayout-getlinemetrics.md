# IDWriteTextLayout::GetLineMetrics

## Description

Retrieves the information about each individual text line of the text string.

## Parameters

### `lineMetrics` [out, optional]

Type: **[DWRITE_LINE_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_line_metrics)***

When this method returns, contains a pointer to an array of structures containing various calculated length values of individual text lines.

### `maxLineCount`

Type: **UINT32**

The maximum size of the *lineMetrics* array.

### `actualLineCount` [out]

Type: **UINT32***

When this method returns, contains the actual size of the *lineMetrics* array that is needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If *maxLineCount* is not large enough E_NOT_SUFFICIENT_BUFFER, which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER), is
returned and **actualLineCount* is set to the number of lines
needed.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)