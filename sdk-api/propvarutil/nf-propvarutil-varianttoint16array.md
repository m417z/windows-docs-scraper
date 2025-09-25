# VariantToInt16Array function

## Description

Extracts data from a vector structure into an **Int16** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `prgn` [out]

Type: **SHORT***

Pointer to the **Int16** data extracted from source variant structure.

### `crgn` [in]

Type: **ULONG**

Specifies **Int16** array size.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of **Int16** elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.