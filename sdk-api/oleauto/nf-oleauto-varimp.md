# VarImp function

## Description

Performs a bitwise implication on two variants.

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
| FALSE | FALSE | TRUE |
| FALSE | NULL | TRUE |
| NULL | TRUE | TRUE |
| NULL | FALSE | NULL |
| NULL | NULL | NULL |

Because **VarImp** performs bitwise operations on *pvarLeft* and *pvarRight* instead of logical operations a *pvarResult* of TRUE is returned by this function call.