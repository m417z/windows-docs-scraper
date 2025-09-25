# IISDB_NBIT::GetRecordDescriptionBodyLocation

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Receives the value of the description_body_location field
from a record in an Integrated Services Digital Broadcasting (ISDB)
network broadcaster information table (NBIT).
This field value indicates the location of the table where the information contents are described.

## Parameters

### `dwRecordIndex` [in]

Index of a record containing descriptors in the NBIT.

### `pbVal` [out]

Receives a 2-bit code that indicates the location of the descriptors. This can be any of the following values:

| Value | Meaning |
| --- | --- |
| 00 | Undefined |
| 01 | Detailed information is provided in the actual transport stream (TS) table |
| 10 | Detailed information is provided in the service information (SI) prime transport stream (TS) table |
| 11 | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_NBIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_nbit)