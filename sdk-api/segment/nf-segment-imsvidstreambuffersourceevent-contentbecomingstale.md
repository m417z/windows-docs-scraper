# IMSVidStreamBufferSourceEvent::ContentBecomingStale

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP Service Pack 1 or later.

The **CertificateSuccess** method is called when the stream buffer source lags behind the stream buffer sink by more than a preset number of files.

## Return value

Return S_OK or an error code.

## Remarks

This event corresponds to the STREAMBUFFER_EC_CONTENT_BECOMING_STALE event in the Stream Buffer Engine. See [Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes).

## See also

[IMSVidStreamBufferSourceEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent)