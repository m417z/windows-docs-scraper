# VarAdd function

## Description

Returns the sum of two variants.

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
| One expression is a string and the other a character | Addition |
| One expression is numeric and the other a string | Addition |
| Both expressions are numeric | Addition |
| Either expression is null | Null |
| Both expressions are empty | Integer |