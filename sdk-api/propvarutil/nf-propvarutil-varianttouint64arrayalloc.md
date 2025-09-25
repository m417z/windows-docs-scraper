# VariantToUInt64ArrayAlloc function

## Description

Extracts data from a vector structure into a newly-allocated unsigned **Int64** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pprgn` [out]

Type: **ULONGLONG****

The address of a pointer to the unsigned **Int64** data extracted from source variant structure.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of unsigned **Int64** elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.