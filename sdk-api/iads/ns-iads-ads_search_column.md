# ADS_SEARCH_COLUMN structure

## Description

The **ADS_SEARCH_COLUMN** structure specifies the contents of a search column in the query returned from the directory service database.

## Members

### `pszAttrName`

A null-terminated Unicode string that contains the name of the attribute whose values are contained in the current search column.

### `dwADsType`

Value from the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) enumeration that indicates how the attribute values are interpreted.

### `pADsValues`

Array of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures that contain values of the attribute in the current search column for the current row.

### `dwNumValues`

Size of the **pADsValues** array.

### `hReserved`

Reserved for internal use by providers.

## Remarks

The **ADS_SEARCH_COLUMN** structure only contains a pointer to the array of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures. Memory for the structure must be allocated separately.

For more information about **ADS_SEARCH_COLUMN**, see [IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn).

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)

[IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn)