# IDvbDataBroadcastDescriptor::GetSelectorLength

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the length of the selector in a DVB data broadcast descriptor, in bytes. The selector is defined by the
data broadcast specification for the network.

## Parameters

### `pbVal` [out]

Receives the selector length.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbDataBroadcastDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbdatabroadcastdescriptor)