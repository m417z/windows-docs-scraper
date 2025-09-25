# VariantToUInt32 function

## Description

Extracts unsigned **Int32** property value of a variant structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `pulRet` [out]

Type: **ULONG***

Pointer to the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.