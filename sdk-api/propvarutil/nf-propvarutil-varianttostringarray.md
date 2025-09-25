# VariantToStringArray function

## Description

Extracts data from a vector structure into a String array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `prgsz` [out]

Type: **PWSTR***

Pointer to the string data extracted from source variant structure.

### `crgsz` [in]

Type: **ULONG**

Specifies string array size.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of string elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.