# IMSVidStreamBufferSource2::put_RateEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **put_RateEx** method sets the playback rate, and sets the frame rate for fast-forward play ("trick mode").

## Parameters

### `dwRate` [in]

Playback rate. The valid range is (*dRate* >= 0.1 || *dRate* <= 0.1).

### `dwFramesPerSecond` [in]

Frames per second for fast-forward play. For more information, see [IStreamBufferMediaSeeking2::SetRateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffermediaseeking2-setrateex).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSource2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersource2)