# EVT_TR_ENUMERATE_SECURE_SERVICES callback function

## Description

## Parameters

### `MasterDevice`

### `Index`

### `SecureServiceDescription`

### `DescriptionSize`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

EVT_TR_ENUMERATE_SECURE_SERVICES EvtTrEnumerateSecureServices;

// Definition

NTSTATUS EvtTrEnumerateSecureServices
(
    WDFDEVICE MasterDevice
    ULONG Index
    PUCHAR SecureServiceDescription
    ULONG * DescriptionSize
)
{...}

```

## Remarks

## See also