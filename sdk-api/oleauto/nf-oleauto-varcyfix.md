# VarCyFix function

## Description

Retrieves the integer portion of a variant of type currency.

## Parameters

### `cyIn` [in]

The currency variant.

### `pcyResult` [out]

The resulting variant. If the variant is negative, then the first negative integer greater than or equal to the variant is returned.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.