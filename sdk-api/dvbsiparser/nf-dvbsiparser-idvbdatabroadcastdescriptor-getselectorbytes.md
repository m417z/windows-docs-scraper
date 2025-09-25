# IDvbDataBroadcastDescriptor::GetSelectorBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the data from the selector in a Digital Video Broadcast (DVB) data broadcast descriptor. The selector is defined by the broadcast standard for the network.

## Parameters

### `pbLen` [in, out]

On input, specifies the size of the buffer (pointed to by the *pbVal* parameter) allocated for the selector data, in bytes. On output, gets the actual length of the selector data.

### `pbVal` [out]

Receives the selector bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbDataBroadcastDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbdatabroadcastdescriptor)