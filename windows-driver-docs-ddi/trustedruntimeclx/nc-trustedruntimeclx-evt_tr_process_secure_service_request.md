# EVT_TR_PROCESS_SECURE_SERVICE_REQUEST callback function

## Description

## Parameters

### `ServiceDevice`

### `SessionContext`

### `RequestHandle`

### `Priority`

### `Request`

### `Flags`

### `BytesWritten`

### `RequestContext`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_PROCESS_SECURE_SERVICE_REQUEST EvtTrProcessSecureServiceRequest;

// Definition

NTSTATUS EvtTrProcessSecureServiceRequest
(
    WDFDEVICE ServiceDevice
    WDFOBJECT SessionContext
    PVOID RequestHandle
    KPRIORITY Priority
    PTR_SERVICE_REQUEST Request
    ULONG Flags
    PULONG_PTR BytesWritten
    PVOID * RequestContext
)
{...}

```

## Remarks

## See also