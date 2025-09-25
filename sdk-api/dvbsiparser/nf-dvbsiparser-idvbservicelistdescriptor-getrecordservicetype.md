# IDvbServiceListDescriptor::GetRecordServiceType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the service_type field value from a Digital Video Broadcast (DVB) service descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [IDvbServiceListDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicelistdescriptor-getcountofrecords) method to get the number of records in the logical channel descriptor.

### `pbVal` [out]

Receives the service type. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x00 | Reserved for future use. |
| 0x01 | Digital television service. (MPEG-2 SD material should use this type.) |
| 0x02 | Digital radio sound service. (MPEG-1 Layer 2 audio material should use this type.) |
| 0x03 | Teletext service. |
| 0x04 | NVOD reference service. (MPEG-2 SD material should use this type.) |
| 0x05 | NVOD time-shifted service. (MPEG-2 SD material should use this type.) |
| 0x06 | Mosaic service. |
| 0x07 - 0x09 | Reserved for future use. |
| 0x0A | Advanced codec digital radio sound service. |
| 0x0B | Advanced codec mosaic service. |
| 0x0C | Data broadcast service. |
| 0x0D | Reserved for Common Interface Usage (EN 5022). |
| 0x0E | RCS Map (see EN 301 790 [7]). |
| 0x0F | RCS FLS (see EN 301 790 [7]). |
| 0x10 | DVB MHP service. |
| 0x11 | MPEG-2 HD digital television service. |
| 0x12 - 0x15 | Reserved for future use. |
| 0x16 | Advanced codec SD digital television service. |
| 0x17 | Advanced codec SD NVOD time-shifted service. |
| 0x18 | Advanced codec SD NVOD reference service. |
| 0x19 | Advanced codec HD digital television service. |
| 0x1A | Advanced codec HD NVOD time-shifted service. |
| 0x1B | Advanced codec HD NVOD reference service. |
| 0x1C - 0x7F | Reserved for future use. |
| 0x80 - 0xFE | User-defined. |
| 0xFF | Reserved for future use. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbServiceListDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicelistdescriptor)

[IDvbServiceListDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicelistdescriptor-getcountofrecords)