# VarEqv function

## Description

Performs a bitwise equivalence on two variants.

## Parameters

### `pvarLeft` [in]

The first variant.

### `pvarRight` [in]

The second variant.

### `pvarResult` [out]

The result variant.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If each bit in *pvarLeft* is equal to the corresponding bit in *pvarRight* then TRUE is returned. Otherwise FALSE is returned.