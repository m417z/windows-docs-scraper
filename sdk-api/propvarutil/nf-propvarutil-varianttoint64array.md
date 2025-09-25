# VariantToInt64Array function

## Description

Extracts data from a vector structure into an **Int64** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `prgn` [out]

Type: **LONGLONG***

Pointer to the Int64 data extracted from source variant structure.

### `crgn` [in]

Type: **ULONG**

Specifies Int64 array size.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of Int64 elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.