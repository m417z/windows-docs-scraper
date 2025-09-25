# IATSC_VCT::GetRecordEtmLocation

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordEtmLocation** method returns the extended text message (ETM) location for a record in the EIT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IATSC_VCT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsc_vct-getcountofrecords) method to get the number of records in the VCT.

### `pbVal` [out]

Receives the ETM_location field.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IATSC_VCT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_vct)