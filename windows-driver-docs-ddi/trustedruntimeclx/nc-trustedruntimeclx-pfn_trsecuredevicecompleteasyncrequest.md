# *PFN_TRSECUREDEVICECOMPLETEASYNCREQUEST callback function

## Description

## Parameters

### `BindContext`

### `RequestHandle`

### `Result`

### `BytesWritten`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

*PFN_TRSECUREDEVICECOMPLETEASYNCREQUEST *PfnTrsecuredevicecompleteasyncrequest;

// Definition

NTSTATUS *PfnTrsecuredevicecompleteasyncrequest
(
    WDFOBJECT BindContext
    PVOID RequestHandle
    NTSTATUS Result
    ULONG_PTR BytesWritten
)
{...}

```

## Remarks

## See also