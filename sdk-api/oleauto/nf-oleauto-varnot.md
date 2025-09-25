# VarNot function

## Description

Performs the bitwise not negation operation on a variant.

## Parameters

### `pvarIn` [in]

The variant.

### `pvarResult` [out]

The result variant.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function operates as follows.

| *pvarIn* | *pvarResult* |
| --- | --- |
| TRUE | TRUE |
| FALSE | TRUE |
| NULL | NULL |