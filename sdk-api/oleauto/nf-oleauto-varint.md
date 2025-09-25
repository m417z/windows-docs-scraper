# VarInt function

## Description

Returns the integer portion of a variant.

## Parameters

### `pvarIn` [in]

The variant.

### `pvarResult` [out]

The result variant.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the variant is negative, then the first negative integer less than or equal to the variant is returned.