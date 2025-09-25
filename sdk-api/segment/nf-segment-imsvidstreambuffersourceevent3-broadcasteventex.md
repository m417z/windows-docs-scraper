# IMSVidStreamBufferSourceEvent3::BroadcastEventEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **BroadcastEventEx** method is called when the [MSVidStreamBufferSource](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695136(v=vs.85)) object receives a broadcast event through the [IBroadcastEventEx](https://learn.microsoft.com/previous-versions/dd376295(v=vs.85)) interface.

## Parameters

### `Guid` [in]

GUID that specifies the event.

### `Param1` [in]

First implementation-dependent parameter.

### `Param2` [in]

Second implementation-dependent parameter.

### `Param3` [in]

Third implementation-dependent parameter.

### `Param4` [in]

Fourth implementation-dependent parameter.

## Return value

Return S_OK or an error code.

## Remarks

For more information, see [IBroadcastEventEx::FireEx](https://learn.microsoft.com/previous-versions/dd376296(v=vs.85)).

## See also

[IMSVidStreamBufferSourceEvent3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent3)