# ISCTE_EAS::GetLocationCodes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetLocationCodes** method returns location codes from the EAS table.

## Parameters

### `bIndex` [in]

The zero-based index of the location codes to retrieve. Call [ISCTE_EAS::GetLocationCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getlocationcount) to get the number of locations.

### `pbState` [out]

Receives the state_code field.

### `pbCountySubdivision` [out]

Receives the county_subdivision field.

### `pwCounty` [out]

Receives the county_code field.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of range. |
| **MPEG2_E_UNINITIALIZED** | The [ISCTE_EAS::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-initialize) method was not called. |
| **S_OK** | The method succeeded. |

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)