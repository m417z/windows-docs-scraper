# IIsdbSiParser2::GetSDT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a
service description table (SDT) from an Integrated Services Digital Broadcast (ISDB) transport stream. An SDT
lists the names and other parameters of the services in an MPEG-2 transport stream.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For an SDT, this value is 0x42 for an actual transport stream, or 0x46 for another stream.

### `pwTransportStreamId`

Pointer to the transport_stream_id field. This field value uniquely identifies the transport stream that contains the SDT.

### `ppSDT` [out]

Receives a pointer to the [IISDB_SDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdt) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_SDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdt)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)