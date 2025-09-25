# VariantToStringAlloc function

## Description

Extracts the variant value of a variant structure to a newly-allocated string. If no value can be extracted, then a default value is assigned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `ppszBuf` [out]

Type: **PWSTR**

Pointer to the extracted property value if one exists; otherwise, empty.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.