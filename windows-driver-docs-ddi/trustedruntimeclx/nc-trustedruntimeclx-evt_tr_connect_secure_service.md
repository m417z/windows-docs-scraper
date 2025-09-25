# EVT_TR_CONNECT_SECURE_SERVICE callback function

## Description

## Parameters

### `ServiceDevice`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_CONNECT_SECURE_SERVICE EvtTrConnectSecureService;

// Definition

NTSTATUS EvtTrConnectSecureService
(
    WDFDEVICE ServiceDevice
)
{...}

```

## Remarks

## See also