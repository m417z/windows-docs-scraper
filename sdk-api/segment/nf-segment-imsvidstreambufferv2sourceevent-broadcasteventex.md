# IMSVidStreamBufferV2SourceEvent::BroadcastEventEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when an SBE2 source filter receives any event fired by a call to [IBroadcastEventEx::FireEx](https://learn.microsoft.com/previous-versions/dd376296(v=vs.85)).

## Parameters

### `Guid` [in]

**BSTR** object that contains the GUID that identifies the event.

### `Param1` [in]

Specifies the first implementation-dependent parameter.

### `Param2` [in]

Specifies the second implementation-dependent parameter.

### `Param3` [in]

Specifies the third implementation-dependent parameter.

### `Param4` [in]

Specifies the fourth implementation-dependent parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBroadcastEventEx::FireEx](https://learn.microsoft.com/previous-versions/dd376296(v=vs.85))

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)