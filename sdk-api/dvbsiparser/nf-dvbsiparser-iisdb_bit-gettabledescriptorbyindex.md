# IISDB_BIT::GetTableDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns a descriptor for a specified table
in an Integrated Services Digital Broadcasting (ISDB) broadcaster
information table
(BIT).

## Parameters

### `dwIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_BIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_bit-getcountofrecords) method to get the number of records in the BIT.

### `ppDescriptor` [out]

Specifies which descriptor to retrieve, indexed from zero.
Call the [IISDB_BIT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_bit-getrecordcountofdescriptors) method
to get the number of descriptors for a particular record.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_bit)

[IISDB_BIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_bit-getcountofrecords)

[IISDB_BIT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_bit-getrecordcountofdescriptors)