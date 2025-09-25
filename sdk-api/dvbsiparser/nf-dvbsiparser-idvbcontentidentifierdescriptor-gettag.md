# IDvbContentIdentifierDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag for a Digital Video Broadcast (DVB) content identifier descriptor.

## Parameters

### `pbVal` [out]

Receives the content identifier descriptor tag. For content identifier descriptors, this tag value is "0x76".

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbContentIdentifierDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcontentidentifierdescriptor)