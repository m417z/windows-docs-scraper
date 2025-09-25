# PENTROPY_SOURCE_CALLBACK_FUNCTION callback function

## Description

## Parameters

### `hEntropySource`

### `context`

## Return value

Return STATUS_SUCCESS if the operation succeeds.

Otherwise, return an appropriate NTSTATUS values error code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

PENTROPY_SOURCE_CALLBACK_FUNCTION PentropySourceCallbackFunction;

// Definition

NTSTATUS PentropySourceCallbackFunction
(
    ENTROPY_SOURCE_HANDLE hEntropySource
    PVOID context
)
{...}

```

## Remarks

## See also