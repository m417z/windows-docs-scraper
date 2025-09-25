# IIsdbLogoTransmissionDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies an Integrated Services Digital Broadcasting (ISDB) logo transmission descriptor.

## Parameters

### `pbVal` [out]

Receives the tag value. For ISDB logo transmission descriptors, this value is 0xCF.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbLogoTransmissionDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdblogotransmissiondescriptor)