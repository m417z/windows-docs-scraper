# IDvbServiceDescriptor::GetProcessedServiceName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the processed service name from a Digital Video Broadcast (DVB) service descriptor.

## Parameters

### `pbstrName` [out]

Pointer to a buffer that receives the service name. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method calls [IDvbServiceDescriptor2::GetServiceNameW](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicedescriptor2-getservicenamew) to get the processed service name. It is provided to maintain compatibility with the original DVB service descriptor specification.

## See also

[IDvbServiceDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicedescriptor)

[IDvbServiceDescriptor2::GetServiceNameW](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicedescriptor2-getservicenamew)