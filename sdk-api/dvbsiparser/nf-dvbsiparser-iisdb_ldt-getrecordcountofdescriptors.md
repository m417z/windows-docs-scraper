# IISDB_LDT::GetRecordCountOfDescriptors

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns the number of descriptors for a record in
an Integrated Services Digital Broadcasting
(ISDB) linked description table (LDT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number,
indexed from zero. Call the [IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords) method to get the number of records in the LDT.

### `pdwVal` [out]

 Receives the number of descriptors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_LDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_ldt)

[IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords)