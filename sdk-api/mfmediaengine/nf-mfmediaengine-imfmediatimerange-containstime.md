# IMFMediaTimeRange::ContainsTime

## Description

Queries whether a specified time falls within any of the time ranges.

## Parameters

### `time` [in]

The time, in seconds.

## Return value

Returns **TRUE** if any time range contained in this object spans the value of the *time* parameter. Otherwise, returns **FALSE**.

## Remarks

This method returns **TRUE** if the following condition holds for any time range in the list:

*start*
*time*
*time*
*end*

## See also

[IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange)