# IPAT::GetCountOfRecords

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetCountOfRecords** method returns the number of records in the PAT. Each record corresponds to one program.

## Parameters

### `pdwVal` [out]

Receives the number of records.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)