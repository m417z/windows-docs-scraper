# IDvbServiceDescriptor::GetServiceType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the service_type field value from a Digital Video Broadcast (DVB) service descriptor.

## Parameters

### `pbVal` [out]

Receives the service type. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x00 | Reserved for future use. |
| 0x01 | Digital television service. (MPEG-2 standard-definition [SD] material should use this type.) |
| 0x02 | Digital radio sound service. (MPEG-1 Layer 2 audio material should use this type.) |
| 0x03 | Teletext service. |
| 0x04 | Near-video-on-demand (NVOD) reference service. (MPEG-2 SD material should use this type.) |
| 0x05 | NVOD time-shifted service. (MPEG-2 SD material should use this type.) |
| 0x06 | Mosaic service |
| 0x07-0x09 | Reserved for future use. |
| 0x0A | Advanced codec digital radio sound service. |
| 0x0B | Advanced codec mosaic service. |
| 0x0C | Data broadcast service. |
| 0x0D | Reserved for Common Interface Usage (see [CENELEC EN 50221: "Common interface specification for conditional access and other digital video broadcasting decoder applications"](http://broadcasting.ru/pdf-standard-specifications/interfacing/dvb-ci/en50221.pdf) ) |
| 0x0E | Return Channel Satellite (RCS) Map (see [Digital Video Broadcasting (DVB); Interaction channel for satellite distribution systems, ETSI EN 301 790](http://www.dvb.org/technology/standards/a054r4.1.dEn301790.V1.5.1.pdf) ). |
| 0x0F | RCS Forward Link Signalling (FLS) (see [EN 301 790](http://www.dvb.org/technology/standards/a054r4.1.dEn301790.V1.5.1.pdf)). |
| 0x10 | DVB Multimedia Home Platform (MHP) service. |
| 0x11 | MPEG-2 high-definition (HD) digital television service |
| 0x12-0x15 | Reserved for future use. |
| 0x16 | Advanced codec SD digital television service. |
| 0x17 | Advanced codec SD NVOD time-shifted service. |
| 0x18 | Advanced codec SD NVOD reference service. |
| 0x19 | Advanced codec HD digital television service. |
| 0x1A | Advanced codec HD NVOD time-shifted service. |
| 0x1B | Advanced codec HD NVOD time-shifted service. |
| 0x1C - 0x7F | Reserved for future use |
| 0x80 - 0xFE | User-defined |
| 0xFF | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbServiceDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicedescriptor)