# IIsdbLogoTransmissionDescriptor::GetLogoTransmissionType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the logo_transmission_type field from an Integrated Services Digital Broadcasting (ISDB) logo transmission descriptor. This field contains a code that indicates the logo transmission type.

## Parameters

### `pbVal` [out]

Receives the logo transmission type. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x01 | Common data table (CDT) transmission scheme 1, which refers to CDT directly using download data identification. |
| 0x02 | CDT transmission scheme 2, which refers to CDT indirectly using download data identification. |
| 0x03 | Simple logo system. |
| 0x04-0xFF | Reserved for future use. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbLogoTransmissionDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdblogotransmissiondescriptor)