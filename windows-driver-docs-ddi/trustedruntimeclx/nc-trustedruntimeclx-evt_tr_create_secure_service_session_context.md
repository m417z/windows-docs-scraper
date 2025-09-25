# EVT_TR_CREATE_SECURE_SERVICE_SESSION_CONTEXT callback function

## Description

## Parameters

### `ServiceDevice`

### `SessionContextObject`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_CREATE_SECURE_SERVICE_SESSION_CONTEXT EvtTrCreateSecureServiceSessionContext;

// Definition

NTSTATUS EvtTrCreateSecureServiceSessionContext
(
    WDFDEVICE ServiceDevice
    WDFOBJECT * SessionContextObject
)
{...}

```

## Remarks

## See also