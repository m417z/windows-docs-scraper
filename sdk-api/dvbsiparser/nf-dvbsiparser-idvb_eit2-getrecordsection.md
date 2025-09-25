# IDVB_EIT2::GetRecordSection

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the number of a section containing an event information table (EIT) record.

## Parameters

### `dwRecordIndex` [in]

The record number, indexed from 0. Call [IDVB_EIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_eit-getcountofrecords) to get the number of records in the EIT.

### `pbVal` [out]

Receives the number of the section containing the specified record. A value of 0 indicates the present section; a value of 1 indicates the following section.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **MPEG2_E_UNINITIALIZED** | The [Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_eit-initialize) method was not called. |

## See also

[IDVB_EIT2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_eit2)