# IDvbSubtitlingDescriptor::GetRecordAncillaryPageID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the ancillary page identifier for a Digital Video Broadcast (DVB) subtitling descriptor. The DVB subtitling segments signalling the ancillary page identifier are decoded if the previous data in the subtitling descriptor matches the user's selection criteria.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)

### `pwVal` [out]

Receives the ancillary page identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the subtitling descriptor has no ancillary page, the values in
the ancillary_page_id and composition_page_id fields of the descriptor are the same.

 The ancillary_page_id is never signalled in a composition segment. It may be signalled in color
lookup table (CLUT) definition segments, object segments, or any other type of segment.

## See also

[IDvbSubtitlingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsubtitlingdescriptor)

[IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)