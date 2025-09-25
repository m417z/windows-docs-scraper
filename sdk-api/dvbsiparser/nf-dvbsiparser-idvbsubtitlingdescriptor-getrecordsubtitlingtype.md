# IDvbSubtitlingDescriptor::GetRecordSubtitlingType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the subtitling component type from a DVB subtitling descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)

### `pbVal` [out]

Receives the subtitling component type code. This can be any of the following values:

| Value | Meaning |
| --- | --- |
| 0x00 | Reserved for future use |
| 0x01 | European Broadcasting Union (EBU) teletext subtitles |
| 0x02 | Associated EBU teletext |
| 0x03 | Vertical blanking interval (VBI) data |
| 0x04 - 0x0F | Reserved for future use |
| 0x10 | DVB subtitles (normal) with no monitor aspect ratio criticality |
| 0x11 | DVB subtitles (normal) for display on 4:3 aspect ratio monitor |
| 0x12 | DVB subtitles (normal) for display on 16:9 aspect ratio monitor |
| 0x13 | DVB subtitles (normal) for display on 2.21:1 aspect ratio monitor |
| 0x14 - 0x1F | Reserved for future use |
| 0x20 | DVB subtitles (for the hard-of-hearing) with no monitor aspect ratio criticality |
| 0x21 | DVB subtitles (for the hard-of-hearing) for display on 4:3 aspect ratio monitor |
| 0x22 | DVB subtitles (for the hard-of-hearing) for display on 16:9 aspect ratio monitor |
| 0x23 | DVB subtitles (for the hard-of-hearing) for display on 2.21:1 aspect ratio monitor |
| 0x24 - 0xAF | Reserved for future use |
| 0xB0 - 0xFE | User-defined |
| 0xFF | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbSubtitlingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsubtitlingdescriptor)

[IDvbSubtitlingDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsubtitlingdescriptor-getcountofrecords)