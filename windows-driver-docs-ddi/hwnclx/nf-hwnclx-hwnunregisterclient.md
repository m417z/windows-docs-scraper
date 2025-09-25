# HwNUnregisterClient function

## Description

Unregisters the hardware notification client driver and its callback functions with the class extension. This function should be invoked when the client driver is unloaded.

## Parameters

### `Driver` [in]

Handle to the client drivers framework driver object.

## Return value

Returns STATUS_SUCCESS if function succeeds. Returns STATUS_INVALID_PARAMETER if corresponding client driver can't be found. Otherwise, it returns one of the error status values defined in Ntstatus.h.

## Syntax

```cpp
FORCEINLINE NTSTATUS  HwNUnregisterClient(
  _In_ WDFDRIVER  Driver
);
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)