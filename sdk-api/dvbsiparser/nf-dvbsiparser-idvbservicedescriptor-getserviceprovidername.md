# IDvbServiceDescriptor::GetServiceProviderName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the service provider name from a Digital Video Broadcast (DVB) service descriptor.

## Parameters

### `pszName`

Pointer to a buffer that receives the service provider name. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbServiceDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicedescriptor)