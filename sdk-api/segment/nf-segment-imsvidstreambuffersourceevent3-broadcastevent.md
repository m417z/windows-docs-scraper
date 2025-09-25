# IMSVidStreamBufferSourceEvent3::BroadcastEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **BroadcastEvent** method is called when the [MSVidStreamBufferSource](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695136(v=vs.85)) object receives a broadcast event through the [IBroadcastEvent](https://learn.microsoft.com/previous-versions/dd376294(v=vs.85)) interface.

## Parameters

### `Guid` [in]

GUID that specifies the event. For more information, see [IBroadcastEvent::Fire](https://learn.microsoft.com/previous-versions/ms784798(v=vs.85)).

## Return value

Return S_OK or an error code.

## See also

[IMSVidStreamBufferSourceEvent3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent3)