# IDvbLinkageDescriptor::GetLinkageType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code that uniquely identifies the linkage type from a Digital Video Broadcast (DVB) linkage descriptor.

## Parameters

### `pbVal` [out]

Receives the linkage type code. For a list of linkage type codes, see Table 58 in Section 6.2.19 of the *DVB Specification for Service Information (SI) in DVB
systems
DVB (Document A038 Rev. 4)*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLinkageDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblinkagedescriptor)