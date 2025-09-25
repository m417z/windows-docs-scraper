# IISDB_NBIT::GetRecordInformationId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

an Integrated Services Digital Broadcasting (ISDB) network broadcaster information table (NBIT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords) method to get the number
of records in the NBIT.

### `pwVal` [out]

Receives the information_type field for the record.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)