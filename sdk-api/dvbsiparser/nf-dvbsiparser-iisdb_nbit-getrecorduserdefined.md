# IISDB_NBIT::GetRecordUserDefined

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the user_defined field from an Integrated Services Digital Broadcasting (ISDB) network broadcaster information table (NBIT).

## Parameters

### `dwRecordIndex` [in]

Record containing the user-defined field, indexed from zero.
Call the [IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords)  method to get the number of records in the NBIT.

### `pbVal` [out]

Receives the user_defined field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)

[IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords)