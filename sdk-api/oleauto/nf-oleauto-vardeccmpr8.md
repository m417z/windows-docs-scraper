# VarDecCmpR8 function

## Description

Compares a variant of type decimal with the a value of type double.

## Parameters

### `pdecLeft` [in]

The first variant.

### `dblRight` [in]

The second variant.

## Return value

This function can return one of these values.

| Return code/value | Description |
| --- | --- |
| **VARCMP_LT**<br><br>0 | *pdecLeft* is less than *dblRight*. |
| **VARCMP_EQ**<br><br>1 | The two parameters are equal. |
| **VARCMP_GT**<br><br>2 | *pdecLeft* is greater than *dblRight*. |
| **VARCMP_NULL**<br><br>3 | Either expression is null. |