# IDvbTeletextDescriptor::GetRecordMagazineNumber

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the magazine number from a Digital Video Broadcast (DVB) teletext descriptor.
A *magazine* is a sequence of one or more pages in an enhanced-teletext packet that are normally repeatedly transmitted in numerical sequence

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call
[IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords).

### `pbVal` [out]

Receives the magazine number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbTeletextDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbteletextdescriptor)

[IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)