# VarCyCmp function

## Description

Compares two variants of type currency.

## Parameters

### `cyLeft` [in]

The first variant.

### `cyRight` [in]

The second variant.

## Return value

This function can return one of these values.

| Return code/value | Description |
| --- | --- |
| **VARCMP_LT**<br><br>0 | *cyLeft* is less than *cyRight*. |
| **VARCMP_EQ**<br><br>1 | The two parameters are equal. |
| **VARCMP_GT**<br><br>2 | *cyLeft* is greater than *cyRight*. |
| **VARCMP_NULL**<br><br>3 | Either expression is null. |