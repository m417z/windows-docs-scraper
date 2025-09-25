# IPAT::FindRecordProgramMapPid

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **FindRecordProgramMapPid** method returns the packet identifier (PID) for the program map table (PMT) associated with a given program number.

## Parameters

### `wProgramNumber` [in]

Specifies the program number.

### `pwVal` [out]

Receives the PID.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_NOT_PRESENT** | The table does not contain the specified program number. |
| **S_OK** | The method succeeded. |

## See also

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)