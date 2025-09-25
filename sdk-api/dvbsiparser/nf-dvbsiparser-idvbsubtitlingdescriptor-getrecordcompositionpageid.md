# IDvbSubtitlingDescriptor::GetRecordCompositionPageID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the composition page identifier for a Digital Video Broadcast (DVB) subtitling descriptor. DVB subtitling segments that signal a
composition page identifier are decoded if the previous data in the subtitling descriptor matches the user's selection criteria.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)

### `pwVal` [out]

Receives the composition page identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The composition page identifier is signalled in at least the subtitling segments that define the data
structure of the subtitle screen: the page composition segment and region composition segments. It
may additionally be signalled in segments containing data on which the composition depends.

## See also

[IDvbSubtitlingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsubtitlingdescriptor)

[IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)