# IIsdbSiParser2::GetSDTT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the software download
trigger table
(SDTT) from an Integrated Services Digital Broadcast (ISDB) transport stream. An SDTT contains download information such as the service identifier, schedule, and
receiver types for revision.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For an SDTT, this value is 0xC34.

### `pwTableIdExt`

Value of the table_id_extension field for the SDTT. This field value identifies a specific instance of the SDTT.

### `ppSDTT` [out]

Receives a pointer to the [IISDB_SDTT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdtt) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_SDTT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdtt)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)