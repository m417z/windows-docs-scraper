# IMSVidStreamBufferV2SourceEvent::StaleFileDeleted

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when the SBE2 source filter receives a **STREAMBUFFER_EC_STALE_FILE_DELETED** event, which indicates that a temporary file has been deleted.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)

[Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes)