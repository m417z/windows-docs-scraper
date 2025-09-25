# IDVB_SDT::GetRecordEITPresentFollowingFlag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordEITPresentFollowingFlag** method queries whether the current transport stream contains present/following EIT information for a particular service.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number for the service, indexed from zero. Call [IDVB_SDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_sdt-getcountofrecords) to get the number of records in the SDT.

### `pfVal` [out]

Pointer to a variable that receives a Boolean value. The value is **TRUE** if the EIT_present_following_flag bit is set, or **FALSE** otherwise. The value **TRUE** indicates that the current transport stream contains present/following EIT information for the service.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_SDT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_sdt)