# VariantToUInt16Array function

## Description

Extracts data from a vector structure into an unsigned **Int16** array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `prgn` [out]

Type: **USHORT***

Pointer to the unsigned **Int16** data extracted from source variant structure.

### `crgn` [in]

Type: **ULONG**

Specifies unsigned **Int16** array size.

### `pcElem` [out]

Type: **ULONG***

Pointer to the count of unsigned **Int16** elements extracted from source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.