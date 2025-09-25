# IDvbPrivateDataSpecifierDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies a Digital Video Broadcast (DVB) private data descriptor.

## Parameters

### `pbVal` [out]

Receives the private descriptor identifier tag. For private data descriptors, this value is 0x5F.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbPrivateDataSpecifierDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbprivatedataspecifierdescriptor)