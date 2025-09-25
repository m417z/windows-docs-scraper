# IDvbTeletextDescriptor::GetRecordPageNumber

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the page number a Digital Video Broadcast (DVB) teletext descriptor. The page number identifies the page of teletext that is broadcast.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors,
call [IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)

### `pbVal` [out]

Receives the page number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbTeletextDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbteletextdescriptor)

[IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)