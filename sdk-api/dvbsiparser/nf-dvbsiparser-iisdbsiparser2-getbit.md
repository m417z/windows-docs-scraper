# IIsdbSiParser2::GetBIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the broadcaster information table (BIT) from an Integrated Services Digital Broadcasting (ISDB) transport stream. A BIT contains a broadcaster unit and the service information transmission parameter
for each broadcaster unit.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For a BIT, this value is 0xC4.

### `pwOriginalNetworkId`

Pointer to the original_network_id field for the BIT. This field contains an identifier for the broadcaster that originates the
MPEG-2 transport stream

### `ppBIT` [out]

Receives a pointer to the [IISDB_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_bit) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_bit)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)