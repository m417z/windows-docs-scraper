# EVT_TR_DESTROY_SECURE_SERVICE_CONTEXT callback function

## Description

## Parameters

### `ServiceDevice`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_DESTROY_SECURE_SERVICE_CONTEXT EvtTrDestroySecureServiceContext;

// Definition

NTSTATUS EvtTrDestroySecureServiceContext
(
    WDFDEVICE ServiceDevice
)
{...}

```

## Remarks

## See also