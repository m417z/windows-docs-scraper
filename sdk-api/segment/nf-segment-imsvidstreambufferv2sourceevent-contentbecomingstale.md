# IMSVidStreamBufferV2SourceEvent::ContentBecomingStale

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when the SBE2 source filter receives a **STREAMBUFFER_EC_CONTENT_BECOMING_STALE** event, which indicates the stream buffer source lags behind the stream buffer sink by more than a preset number of files.

For more information, see [IStreamBufferConfigure::GetBackingFileCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferconfigure-getbackingfilecount).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)

[IStreamBufferConfigure::GetBackingFileCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferconfigure-getbackingfilecount)

[Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes)