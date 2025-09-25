# IMFMediaTimeRange::GetStart

## Description

Gets the start time for a specified time range.

## Parameters

### `index` [in]

The zero-based index of the time range to query. To get the number of time ranges, call [IMFMediaTimeRange::GetLength](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediatimerange-getlength).

### `pStart` [out]

Receives the start time, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **TimeRanges.start** method in HTML5.

## See also

[IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange)