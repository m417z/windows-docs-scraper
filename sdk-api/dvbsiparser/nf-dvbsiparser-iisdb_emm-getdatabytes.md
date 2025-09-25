# IISDB_EMM::GetDataBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the data
from an Integrated Services
Digital Broadcasting (ISDB) entitlement management message (EMM) table.

## Parameters

### `pwBufferLength` [in, out]

On input, specifies the length in bytes of the buffer (specified in the *pbBuffer* parameter) that receives the EMM table data. On output, gets the actual length of the data returned in *pbBuffer*.

### `pbBuffer` [out]

Receives the data from the EMM table.
The allocated size of this buffer must be greater than or equal to the value
that the *pwBufferLength* parameter points to.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm)