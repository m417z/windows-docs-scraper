# EVT_TR_DESTROY_SECURE_SERVICE_SESSION_CONTEXT callback function

## Description

## Parameters

### `ServiceDevice`

### `SessionContextObject`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_DESTROY_SECURE_SERVICE_SESSION_CONTEXT EvtTrDestroySecureServiceSessionContext;

// Definition

NTSTATUS EvtTrDestroySecureServiceSessionContext
(
    WDFDEVICE ServiceDevice
    WDFOBJECT * SessionContextObject
)
{...}

```

## Remarks

## See also