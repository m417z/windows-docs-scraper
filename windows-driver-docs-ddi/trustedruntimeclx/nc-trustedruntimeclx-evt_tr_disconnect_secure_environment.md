# EVT_TR_DISCONNECT_SECURE_ENVIRONMENT callback function

## Description

## Parameters

### `MasterDevice`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_DISCONNECT_SECURE_ENVIRONMENT EvtTrDisconnectSecureEnvironment;

// Definition

NTSTATUS EvtTrDisconnectSecureEnvironment
(
    WDFDEVICE MasterDevice
)
{...}

```

## Remarks

## See also