# VarMul function

## Description

Returns the result from multiplying two variants.

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

| Condition | Result |
| --- | --- |
| Both expressions are strings, dates, characters, or boolean values | Multiplication |
| One expression is a string and the other a character | Multiplication |
| One expression is numeric and the other a string | Multiplication |
| Both expressions are numeric | Multiplication |
| Either expression is null | Null |
| Both expressions are empty | Empty string |

Boolean values are converted to -1 for FALSE and 0 for TRUE.