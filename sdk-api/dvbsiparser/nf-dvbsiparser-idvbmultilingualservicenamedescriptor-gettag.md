# IDvbMultilingualServiceNameDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag identifying a Digital Video Broadcast (DVB) multilingual service name descriptor.

## Parameters

### `pbVal` [out]

Receives the service list descriptor tag. Typically, this value is 0x5D for multilingual service name descriptors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbMultilingualServiceNameDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbmultilingualservicenamedescriptor)