# EVT_TR_CREATE_SECURE_SERVICE_CONTEXT callback function

## Description

## Parameters

### `MasterDevice`

### `ServiceGuid`

### `ServiceDevice`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_CREATE_SECURE_SERVICE_CONTEXT EvtTrCreateSecureServiceContext;

// Definition

NTSTATUS EvtTrCreateSecureServiceContext
(
    WDFDEVICE MasterDevice
    LPCGUID ServiceGuid
    WDFDEVICE ServiceDevice
)
{...}

```

## Remarks

## See also