# IPMT::GetRecordStreamType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetRecordStreamType** method returns the stream type for a given elementary stream in the program.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IPMT::GetCountOfRecords](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-ipmt-getcountofrecords) method to get the number of records in the PMT.

### `pbVal` [out]

Receives the stream_type field.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IPMT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipmt)