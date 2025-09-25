# IDvbLinkageDescriptor::GetPrivateData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the private data from a Digital Video Broadcast (DVB) linkage descriptor.

## Parameters

### `pbLen` [in, out]

On input, specifies the size of the buffer (pointed to by the *pbData* parameter) allocated for the private data, in bytes. On output, gets the actual length of the private data that is received.

### `pbData` [out]

Receives private data from the DVB linkage descriptor.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLinkageDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblinkagedescriptor)