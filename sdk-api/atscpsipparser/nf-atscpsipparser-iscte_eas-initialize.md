# ISCTE_EAS::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Initialize** method initializes the object using captured table section data. This method is called internally by the [IAtscPsipParser::GetEAS](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatscpsipparser-geteas) method, so applications typically should not call it.

## Parameters

### `pSectionList` [in]

Pointer to the [ISectionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist) interface.

### `pMPEGData` [in]

Pointer to the [IMpeg2Data](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data) interface of the [MPEG-2 Sections and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mpeg-2-sections-and-tables-filter) filter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **MPEG2_E_MALFORMED_TABLE** | The EAS table is not well formed. |
| **S_OK** | The method succeeded. |

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)