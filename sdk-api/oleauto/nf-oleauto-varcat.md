# VarCat function

## Description

Concatenates two variants and returns the result.

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
| Both expressions are strings | Concatenated |
| Both expressions are null | Null |
| One expression is null and the other is not null | The non-null type |
| Either expression is a Boolean | FALSE equal to 1 or TRUE equal to -1 |
| Either expression is VT_ERROR | Null |
| Both expressions are numeric | Concatenated and returned as a string |
| One expression is numeric and the other a string | Concatenated |
| Either expression is a date | Date |
| Both expressions are empty | Empty string |