# *PFN_TRSECUREDEVICELOGMESSAGE callback function

## Description

## Parameters

### `BindContext`

### `Device`

### `Severity`

### `Message`

### `Arguments`

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Syntax

```cpp
//Declaration

*PFN_TRSECUREDEVICELOGMESSAGE *PfnTrsecuredevicelogmessage;

// Definition

NTSTATUS *PfnTrsecuredevicelogmessage
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    ULONG Severity
    PCSTR Message
    va_list Arguments
)
{...}

```

## Remarks

## See also