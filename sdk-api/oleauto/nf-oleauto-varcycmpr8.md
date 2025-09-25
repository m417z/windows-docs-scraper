# VarCyCmpR8 function

## Description

Compares a variant of type currency with a value of type double.

## Parameters

### `cyLeft` [in]

The first variant.

### `dblRight` [in]

The second variant.

## Return value

This function can return one of these values.

| Return code/value | Description |
| --- | --- |
| **VARCMP_LT**<br><br>0 | *cyLeft* is less than *dblRight*. |
| **VARCMP_EQ**<br><br>1 | The two parameters are equal. |
| **VARCMP_GT**<br><br>2 | *cyLeft* is greater than *dblRight*. |
| **VARCMP_NULL**<br><br>3 | Either expression is null. |