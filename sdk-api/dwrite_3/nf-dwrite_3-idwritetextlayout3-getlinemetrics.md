# IDWriteTextLayout3::GetLineMetrics

## Description

Retrieves properties of each line.

## Parameters

### `lineMetrics` [out]

The array to fill with line information.

### `maxLineCount`

The maximum size of the lineMetrics array.

### `actualLineCount` [out]

The actual size of the lineMetrics
array that is needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If maxLineCount is not large enough E_NOT_SUFFICIENT_BUFFER,
which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER),
is returned and actualLineCount is set to the number of lines
needed.

## See also

[IDWriteTextLayout3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritetextlayout3)