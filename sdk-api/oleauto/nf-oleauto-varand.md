# VarAnd function

## Description

Performs a bitwise And operation between two variants of any integral type.

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
| TRUE | FALSE | FALSE |
| TRUE | NULL | NULL |
| FALSE | TRUE | FALSE |
| FALSE | FALSE | FALSE |
| FALSE | NULL | FALSE |
| NULL | TRUE | NULL |
| NULL | FALSE | FALSE |
| NULL | NULL | NULL |