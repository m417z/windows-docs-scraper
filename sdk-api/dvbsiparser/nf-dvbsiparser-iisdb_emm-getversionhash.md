# IISDB_EMM::GetVersionHash

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns a hash value for this instance of an Integrated Services
Digital Broadcasting (ISDB) entitlement management message (EMM) table.
Tables that refer to
the same content
will return the same hash value, even though the tables have different version_number and table_id fields. You can use this hash value to identify when
two tables carry the same information,
even if the tables are carried on different transport streams.

## Parameters

### `pdwVersionHash` [out]

Receives the hash value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm)