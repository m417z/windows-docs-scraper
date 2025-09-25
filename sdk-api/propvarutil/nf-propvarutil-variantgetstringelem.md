# VariantGetStringElem function

## Description

Extracts a single wide string element from a variant structure.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `iElem` [in]

Type: **ULONG**

Specifies a vector or array index; otherwise, value must be 0.

### `ppszVal` [out]

Type: **PWSTR***

The address of a pointer to the extracted element value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.