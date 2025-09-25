# IMFMediaTimeRange::AddRange

## Description

Adds a new range to the list of time ranges.

## Parameters

### `startTime` [in]

The start time, in seconds.

### `endTime` [in]

The end time, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the new range intersects a range already in the list, the two ranges are combined. Otherwise, the new range is added to the list.

## See also

[IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange)