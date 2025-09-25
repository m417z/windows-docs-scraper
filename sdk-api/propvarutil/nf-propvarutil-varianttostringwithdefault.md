# VariantToStringWithDefault function

## Description

Extracts the string property value of a variant structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pszDefault` [in]

Type: **LPCWSTR**

Pointer to the default Unicode string property value, for use where no value currently exists.

## Return value

Type: **PCWSTR**

Returns the extracted string value, or default.