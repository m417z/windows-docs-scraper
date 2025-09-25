# VarOr function

## Description

Performs a logical disjunction on two variants.

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

The function operates as follows.

| *pvarLeft* | *pvarRight* | *pvarResult* |
| --- | --- | --- |
| TRUE | TRUE | TRUE |
| TRUE | FALSE | TRUE |
| TRUE | NULL | TRUE |
| FALSE | TRUE | TRUE |
| FALSE | FALSE | FALSE |
| FALSE | NULL | NULL |
| NULL | TRUE | TRUE |
| NULL | FALSE | NULL |
| NULL | NULL | NULL |