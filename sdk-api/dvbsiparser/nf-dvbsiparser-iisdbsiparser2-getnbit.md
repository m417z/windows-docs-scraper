# IIsdbSiParser2::GetNBIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the network board information table (NBIT) from an Integrated Services Digital Broadcast (ISDB) transport stream.
The NBIT describes the programs included in a multiplexed transport stream.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For an NBIT, this value is 0xC5 if the table contains the network board information body, or 0xC6 if the table contains reference information for retrieving the network board information.

### `pwOriginalNetworkId`

Pointer to the original_network_id field for the NBIT. This field contains an identifier for the broadcaster that originates the
MPEG-2 transport stream

### `ppNBIT` [out]

Receives a pointer to the [IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)