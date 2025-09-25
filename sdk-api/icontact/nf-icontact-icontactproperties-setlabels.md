# IContactProperties::SetLabels

## Description

Appends the set of labels passed in to the specified property's label set.
Note: This method does not check for duplicate labels.

## Parameters

### `pszArrayElementName` [in]

Type: **LPCWSTR**

Specifies the property to label.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `dwLabelCount` [in]

Type: **DWORD**

Specifies the count of labels in array.

### `ppszLabels` [in]

Type: **LPCWSTR**

 Specifies an array of LPCWSTR labels.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Labels set successfully. |
| **ERROR_PATH_NOT_FOUND** | No data found for this property name. |
| **ERROR_INVALID_DATATYPE** | Unable to set value for this property due to schema. |