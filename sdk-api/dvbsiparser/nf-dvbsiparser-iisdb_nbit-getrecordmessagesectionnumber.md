# IISDB_NBIT::GetRecordMessageSectionNumber

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the section_number field from a record in Integrated Services Digital Broadcasting (ISDB)
network broadcaster information table (NBIT).
The section_ number field identifies the section so that
the demultiplexer can successfully reconstruct the sections in their original order.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords) method to get the number
of records in the NBIT.

### `pbVal` [out]

Gets the section_number field value from the NBIT record.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)

[IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords)