# IMSVidPlaybackEvent::EndOfMedia

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **EndOfMedia** method is called when playback reaches the end of the source media.

## Parameters

### `lpd` [in]

Specifies a pointer to the [IMSVidPlayback](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback) interface of the playback device.

## Return value

Return S_OK or an error code.

## Remarks

The dispatch identifier (dispid) of this method is **eventidEndOfMedia**.

## See also

[IMSVidPlaybackEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplaybackevent)