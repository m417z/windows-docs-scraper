# IContactProperties::GetPropertyCollection

## Description

Returns an [IContactPropertyCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactpropertycollection) for the current contact.
Optionally, filters the **IContactPropertyCollection** to enumerate only some values.

## Parameters

### `ppPropertyCollection` [out]

Type: **[IContactPropertyCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactpropertycollection)****

On success, points to the new [IContactPropertyCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactpropertycollection).

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `pszMultiValueName` [in]

Type: **LPCWSTR**

Specifies the name of the collection (for example: emailAddresses or [namespace]arrayNode).
If **NULL**, all collections are searched for *ppszLabels*.

### `dwLabelCount` [in]

Type: **DWORD**

Specifies the number of labels in *ppszLabels*.
If zero, all subproperties with labels are returned.

### `ppszLabels` [in]

Type: **LPCWSTR**

Specifies an array of string labels to test for.
All labels in the array must be set to a valid string (not **NULL**).

### `fAnyLabelMatches` [in]

Type: **BOOL**

TRUE if the presence of any label on a given property matches the property.
FALSE if all labels must be present to match the property.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Always returns success. |

## Remarks

Caller can enumerate all child properties of a top-level property with
an optional label filter applied. For example: all emailAddresses where label="work". On success,
collection has been reset to the location before the first element (if any are present).
Call [Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactpropertycollection-next) to begin querying data.