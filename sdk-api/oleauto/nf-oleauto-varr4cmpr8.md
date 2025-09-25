# VarR4CmpR8 function

## Description

Compares two variants of types float and double.

## Parameters

### `fltLeft` [in]

The first variant.

### `dblRight` [in]

The second variant.

## Return value

The function returns the following as a SUCCESS HRESULT.

| Return code/value | Description |
| --- | --- |
| 0 | *fltLeft* is less than *dblRight.* |
| 1 | The two parameters are equal. |
| 2 | *fltLeft* is greater than *dblRight.* |
| 3 | Either expression is NULL. |