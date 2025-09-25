# IPSITables::GetTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an MPEG-2 Program Specific Information (PSI) table from an MPEG-2 transport stream. The table that is returned and its contents depend on the values of the three input parameters to this method.

## Parameters

### `dwTSID` [in]

Transport stream identifier (TSID) for the table that is retrieved (bytes 0 - 15) and the original network ID (ONID) for an Event Information Table (EIT) that is retrieved (bytes 16 - 31).

### `dwTID_PID` [in]

Table identifier (TID) or the program ID (PID) that identifies the transport stream packet.

### `dwHashedVer` [in]

Hash value that identifies the table contents.

### `dwPara4` [in]

PID for a Program Mapping Table or the service ID (SID) for an EIT. Otherwise, not used.

### `ppIUnknown` [out]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the table object that is retrieved. The caller is responsible for freeing the memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPSITables](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipsitables)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)