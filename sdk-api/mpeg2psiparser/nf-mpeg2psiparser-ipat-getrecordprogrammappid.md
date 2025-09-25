# IPAT::GetRecordProgramMapPid

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetRecordProgramMapPid** method returns the packet identifier (PID) for a given record in the PAT.

## Parameters

### `dwIndex` [in]

Specifies the record to retrieve, indexed from zero. Call the [IPAT::GetCountOfRecords](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-ipat-getcountofrecords) method to get the number of records in the PAT.

### `pwVal` [out]

Receives the PID. This value identifies the PID for the packets that contain the program map table (PMT) of the associated program.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)