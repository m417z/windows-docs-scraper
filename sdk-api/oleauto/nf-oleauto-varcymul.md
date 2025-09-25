# VarCyMul function

## Description

Multiplies two variants of type currency.

## Parameters

### `cyLeft` [in]

The first variant

### `cyRight` [in]

The second variant.

### `pcyResult` [out]

The resulting variant.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If any of the fields of *cyLeft* or *cyRight* is left uninitialized, it may default to a large value causing DISP_E_OVERFLOW.