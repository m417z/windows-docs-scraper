# VariantToString function

## Description

Extracts the variant value of a variant structure to a string. If no value can be extracted, then a default value is assigned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pszBuf` [out]

Type: **PWSTR**

Pointer to the extracted property value if one exists; otherwise, empty.

### `cchBuf` [in]

Type: **UINT**

Specifies string length, in characters.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.