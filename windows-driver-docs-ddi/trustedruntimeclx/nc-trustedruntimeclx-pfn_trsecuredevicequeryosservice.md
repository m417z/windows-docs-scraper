# *PFN_TRSECUREDEVICEQUERYOSSERVICE callback function

## Description

## Parameters

### `BindContext`

### `Device`

### `OSServiceGuid`

### `Information`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

*PFN_TRSECUREDEVICEQUERYOSSERVICE *PfnTrsecuredevicequeryosservice;

// Definition

NTSTATUS *PfnTrsecuredevicequeryosservice
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    LPCGUID OSServiceGuid
    PTR_SERVICE_INFORMATION Information
)
{...}

```

## Remarks

## See also