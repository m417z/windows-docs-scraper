# IATSC_VCT::GetRecordIsOutOfBandBitSet

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordIsOutOfBandBitSet** method queries whether the out_of_band bit is set for a particular record in the VCT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IATSC_VCT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsc_vct-getcountofrecords) method to get the number of records in the VCT.

### `pfVal` [out]

Receives a Boolean value. The value is **TRUE** if the out_of_band bit is set, indicating that this channel is carried on an out-of-band physical transmission channel. Otherwise, the value is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_NOT_PRESENT** | The table does not contain an out_of_band bit. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## Remarks

This bit applies only to cable VCTs. If the VCT is a terrestrial VCT, the method returns MPEG2_E_NOT_PRESENT.

## See also

[IATSC_VCT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_vct)