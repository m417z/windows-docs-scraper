# VariantGetUInt32Elem function

## Description

Extracts a single unsigned **Int32** element from a variant structure.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `iElem` [in]

Type: **ULONG**

Specifies vector or array index; otherwise, value must be 0.

### `pnVal` [out]

Type: **ULONG***

Pointer to the extracted element value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.