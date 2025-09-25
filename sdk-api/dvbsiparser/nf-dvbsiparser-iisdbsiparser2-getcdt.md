# IIsdbSiParser2::GetCDT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the common data table (CDT) from an Integrated Services Digital Broadcasting (ISDB) transport stream. A CDT contains data that is needed for receivers and stored in
nonvolatile memory, such as company logos.

## Parameters

### `tableId` [in]

Table identifier for the type of table to retrieve. For a CDT, this value is 0xC8.

### `bSectionNumber` [in]

Specifies the value of the section_number field for the CDT.

### `pwDownloadDataId`

Pointer to the download_data_id field value for the CDT.

### `ppCDT` [out]

Receives a pointer to the [IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)