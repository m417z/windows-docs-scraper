# VariantToInt32Array function

## Description

Extracts data from a vector structure into an **Int32** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `prgn` [out]

Type: **LONG***

Pointer to the **Int32** data extracted from source variant structure.

### `crgn` [in]

Type: **ULONG**

Specifies **Int32** array size.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of **Int32** elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.