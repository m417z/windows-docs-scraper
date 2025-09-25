# IDvbTeletextDescriptor::GetRecordTeletextType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the teletext type code from from a Digital Video Broadcast (DVB) teletext descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)

### `pbVal` [out]

Receives the teletext type code. This can have any of the following values:

| Value | Meaning |
| --- | --- |
| 0x00 | Reserved for future use |
| 0x01 | Initial teletext page |
| 0x02 | Teletext subtitle page |
| 0x03 | Additional information page |
| 0x04 | Program schedule page |
| 0x05 | Teletext subtitle page for hearing-impaired people |
| 0x06 - 0x1F | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbTeletextDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbteletextdescriptor)

[IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)