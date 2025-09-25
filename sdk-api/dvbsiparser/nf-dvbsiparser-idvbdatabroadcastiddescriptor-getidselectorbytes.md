# IDvbDataBroadcastIDDescriptor::GetIDSelectorBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the data from the selector in a Digital Video Broadcast (DVB) data broadcast ID descriptor. The selector is defined by the broadcast standard for the network.

## Parameters

### `pbLen` [in, out]

Specifies or gets the number of selector bytes for this descriptor.

### `pbVal` [out]

Receives the selector bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbDataBroadcastIDDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbdatabroadcastiddescriptor)