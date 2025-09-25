# VarIdiv function

## Description

Converts two variants of any type to integers then returns the result from dividing them.

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
| Both expressions are strings, dates, characters, or boolean values | Division and an integer is returned |
| One expression is a string and the other a character | Division |
| One expression is numeric and the other a string | Division |
| Both expressions are numeric | Division |
| Either expression is null | Null |
| Both expressions are empty | DISP_E_DIVBYZERO |