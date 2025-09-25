# IAMStats::GetValueByIndex

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetValueByIndex` method retrieves a statistic, by index.

## Parameters

### `lIndex` [in]

Zero-based index of the statistic.

### `szName` [out]

Pointer to a variable that receives the name of the statistic.

### `lCount` [out]

Pointer to a variable that receives the number of values that were recorded.

### `dLast` [out]

Pointer to a variable that receives the most recent value that was recorded.

### `dAverage` [out]

Pointer to a variable that receives the average value.

### `dStdDev` [out]

Pointer to a variable that receives the standard deviation of the values. If the count is less than two, the standard deviation is zero.

### `dMin` [out]

Pointer to a variable that receives the minimum value that was recorded.

### `dMax` [out]

Pointer to a variable that receives the maximum value that was recorded.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Index out of range. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The caller must free the string returned in *szName*, by calling the **SysFreeString** function.

To get the number of statistics, call [IAMStats::GetIndex](https://learn.microsoft.com/windows/desktop/api/control/nf-control-iamstats-getindex).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStats Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-iamstats)