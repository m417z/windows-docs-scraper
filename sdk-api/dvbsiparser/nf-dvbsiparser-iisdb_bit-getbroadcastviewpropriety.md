# IISDB_BIT::GetBroadcastViewPropriety

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns the broadcast_view_propriety flag from a record in
an Integrated Services Digital Broadcasting (ISDB) broadcaster
information table
(BIT). The broadcast_view_propriety flag indicates whether the content associated with the broadcaster unit is appropriate for the age-based category of user.

## Parameters

### `pbVal` [out]

Receives the broadcast_view_propriety flag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_bit)