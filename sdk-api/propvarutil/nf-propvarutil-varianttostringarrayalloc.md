# VariantToStringArrayAlloc function

## Description

Extracts data from a vector structure into a newly-allocated String array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pprgsz` [out]

Type: **PWSTR****

The address of a pointer to the string data extracted from source variant structure.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of string elements extracted from source variant structure.

#### - crgsz [in]

Type: **ULONG**

Specifies string array size.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.