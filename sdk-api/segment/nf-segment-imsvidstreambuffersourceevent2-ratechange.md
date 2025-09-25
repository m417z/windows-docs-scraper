# IMSVidStreamBufferSourceEvent2::RateChange

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **RateChange** method is called when the playback rate changes.

## Parameters

### `qwNewRate` [in]

Specifies the new playback rate.

### `qwOldRate` [in]

Specifies the previous playback rate.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## Remarks

For both parameters, 1.0 represents normal speed. Fractional values are allowed. For example, 0.2 would represent a rate that is slower than normal playback and 1.7 would represent a rate that is faster than normal playback.

## See also

[IMSVidStreamBufferSourceEvent2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent2)