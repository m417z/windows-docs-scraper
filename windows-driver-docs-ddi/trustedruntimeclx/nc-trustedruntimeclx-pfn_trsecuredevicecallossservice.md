# *PFN_TRSECUREDEVICECALLOSSSERVICE callback function

## Description

## Parameters

### `BindContext`

### `Device`

### `OSServiceGuid`

### `CallData`

### `BytesWritten`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

*PFN_TRSECUREDEVICECALLOSSSERVICE *PfnTrsecuredevicecallossservice;

// Definition

NTSTATUS *PfnTrsecuredevicecallossservice
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    LPCGUID OSServiceGuid
    PTR_SERVICE_REQUEST CallData
    ULONG_PTR *BytesWritten
)
{...}

```

## Remarks

## See also