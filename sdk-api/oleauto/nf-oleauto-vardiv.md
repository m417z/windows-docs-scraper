# VarDiv function

## Description

Returns the result from dividing two variants.

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
| Both expressions are strings, dates, characters, or boolean values | Double |
| One expression is a string and the other a character | Division and a double is returned |
| One expression is numeric and the other a string | Division and a double is returned |
| Both expressions are numeric | Division and a double is returned |
| Either expression is null | Null |
| *pvarRight* is empty and *pvarLeft* is not empty | DISP_E_DIVBYZERO |
| *pvarLeft* is empty and *pvarRight* is not empty | 0 as type double |
| Both expressions are empty | DISP_E_OVERFLOW |