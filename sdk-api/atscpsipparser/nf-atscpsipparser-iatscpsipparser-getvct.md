# IAtscPsipParser::GetVCT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetVCT** method retrieves the virtual channel table (VCT).

## Parameters

### `tableId` [in]

Specifies the table identifier (TID) of the VCT. Use one of the following values, declared in mpeg2data.h.

| Value | Description |
| --- | --- |
| ATSC_VCT_CABL_TID (0xC9) | Cable |
| ATSC_VCT_TERR_TID (0xC8) | Terrestrial |

### `fGetNextTable` [in]

Boolean value that indicates whether to search for the current table or the next table. If the value is **TRUE**, the method searches for a table with the current_next_indicator flag set to 1. Otherwise, the method searches for a table with the current_next_indicator flag set to 0.

### `ppVCT` [out]

Receives an [IATSC_VCT](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_vct) interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive the table in the allotted time. |
| **MPEG2_E_UNINITIALIZED** | The **Initialize** method was not called. |
| **S_OK** | The method succeeded. |

## Remarks

The method fails if the filter does not receive a matching table within a predetermined length of time.

## See also

[IAtscPsipParser Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatscpsipparser)