# IDvbDataBroadcastDescriptor::GetText

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the text that describes the data
from a Digital Video Broadcast (DVB) data broadcast descriptor.

## Parameters

### `pbLen` [in, out]

Specifies or receives the length of the
description, in bytes.

### `pbVal` [out]

Receives the description text.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbDataBroadcastDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbdatabroadcastdescriptor)