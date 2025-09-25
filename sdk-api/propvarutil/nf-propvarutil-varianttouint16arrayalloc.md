# VariantToUInt16ArrayAlloc function

## Description

Extracts data from a vector structure into a newly-allocated unsigned **Int16** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pprgn` [out]

Type: **USHORT****

Pointer to the address of the unsigned **Int16** data extracted from the source variant structure.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of unsigned **Int16** elements extracted from the source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.