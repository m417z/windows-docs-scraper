# IIsdbLogoTransmissionDescriptor::GetLogoVersion

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the logo_version field from an Integrated Services Digital Broadcasting (ISDB) logo transmission descriptor. This field contains the version number of the logo specified in the descriptor logo_id field.

## Parameters

### `pwVal` [out]

Receives the logo version number. Call the [IIsdbLogoTransmissionDescriptor::GetLogoId](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdblogotransmissiondescriptor-getlogoid) method to get the value of the logo_id field.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbLogoTransmissionDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdblogotransmissiondescriptor)

[IIsdbLogoTransmissionDescriptor::GetLogoId](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdblogotransmissiondescriptor-getlogoid)