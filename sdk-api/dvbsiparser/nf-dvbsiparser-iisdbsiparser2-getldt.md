# IIsdbSiParser2::GetLDT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a
linked description table (LDT) from an Integrated Services Digital Broadcast (ISDB) transport stream. An LDT contains data that is used to collect reference
information from other tables.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For an LDT, this value is 0xC7.

### `pwOriginalServiceId`

Pointer to the original_service_id field for the LDT. This field contains an identifier for the service for this transport stream.

### `ppLDT` [out]

Receives a pointer to the [IISDB_LDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_ldt) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_LDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_ldt)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)