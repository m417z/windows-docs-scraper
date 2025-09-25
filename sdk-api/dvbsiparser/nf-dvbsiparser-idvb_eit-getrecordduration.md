# IDVB_EIT::GetRecordDuration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordDuration** method returns the event duration for a record in the EIT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call [IDVB_EIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_eit-getcountofrecords) to get the number of records in the EIT.

### `pmdVal` [out]

Pointer to an [MPEG_DURATION](https://learn.microsoft.com/previous-versions/dd390732(v=vs.85)) structure allocated by the caller. The method fills the structure with the event duration.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_EIT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_eit)