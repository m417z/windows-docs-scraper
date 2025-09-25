# IISDB_NBIT::GetRecordInformationType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an information_type field from
a record in an Integrated Services Digital Broadcasting (ISDB)
network broadcaster information table (NBIT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords) method to get the number of records in the NBIT.

### `pbVal` [out]

Receives the information_type field. This field can contain any of the following values:

| Value | Meaning |
| --- | --- |
| 0x0 | Undefined |
| 0x1 | Information (key ID: none) |
| 0x2 | Information with service identifier (key ID: service identifier) |
| 0x3 | Information with genre (key ID: content_nibble, user_nibble) |
| 0x4 - 0xF | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)

[IISDB_NBIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_nbit-getcountofrecords)