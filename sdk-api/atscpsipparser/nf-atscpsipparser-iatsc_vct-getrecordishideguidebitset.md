# IATSC_VCT::GetRecordIsHideGuideBitSet

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordIsHideGuideBitSet** method queries whether the hide_guide bit is set for a particular record in the VCT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IATSC_VCT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsc_vct-getcountofrecords) method to get the number of records in the VCT.

### `pfVal` [out]

Receives a Boolean value. The value is **TRUE** if the hide_guide bit is set, or **FALSE** otherwise.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## Remarks

If the hidden bit is set, the hide_guide bit may be set to 0, indicating that this virtual channel should appear in electronic program guide (EPG) displays. If the hidden bit is 0, the hide_guide bit is ignored.

## See also

[IATSC_VCT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_vct)

[IATSC_VCT::GetRecordIsHiddenBitSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsc_vct-getrecordishiddenbitset)