## Description

This resource contains details of the search criteria when fetching a diagnostic data record.

## Members

### `producerNames`

Type: **[LPCWSTR\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
List of producer names to search for. A diagnostic data record that matches at least one of the producer names is included as a result in this search criteria. Use `nullptr` for this value to indicate no filter by producers.

### `producerNameCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of producer names in the list of producer names to search for. Use `0` for this value to indicate no filter by producers.

### `textToMatch`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The sub-string to search for within diagnostic data records. This text is case insensitive.

### `categoryIds`

Type: **[INT32\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
List of category identifiers to search for. A diagnostic data record that matches at least one of the category names is included as a result in this search criteria. Use `nullptr` for this value to indicate no filter by categories.

### `categoryIdCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of categories in the list of category identifiers. Use `0` for this value to indicate no filter by categories.

### `privacyTags`

Type: **[INT32\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
List of privacy tag identifiers to search for. A diagnostic data record that matches at least one of the tags is included as a result in this search criteria. Use `nullptr` for this value to indicate no filter by privacy tags.

### `privacyTagCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of privacy tags in the list of privacy tag identifiers. Use `0` for this value to indicate no filter by tags.

### `coreDataOnly`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
`TRUE` to filter search results to only core data. `FALSE` to return both core and non-core data.

## Remarks

For more details on how core data is defined, see our [**privacy statement**](https://learn.microsoft.com/windows/privacy/windows-diagnostic-data).

## See also