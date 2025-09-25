# IAtscContentAdvisoryDescriptor::GetRecordRatingRegion

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordRatingRegion** method returns the rating region at a specified index.

## Parameters

### `bIndex` [in]

Zero-based index of the rating region. To get the number of rating regions, call [IAtscContentAdvisoryDescriptor::GetRatingRegionCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsccontentadvisorydescriptor-getratingregioncount).

### `pbVal` [out]

Receives the rating_region field.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_OUT_OF_BOUNDS** | The *bIndex* parameter is out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IAtscContentAdvisoryDescriptor Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsccontentadvisorydescriptor)