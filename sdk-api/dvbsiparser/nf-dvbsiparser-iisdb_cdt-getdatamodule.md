# IISDB_CDT::GetDataModule

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Receives the data module from
an Integrated Services Digital Broadcasting (ISDB)
common data table (CDT).

## Parameters

### `pbData` [out]

Pointer to a memory block allocated to receive the data module.
The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)