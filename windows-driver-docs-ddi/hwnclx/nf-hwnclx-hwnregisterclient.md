# HwNRegisterClient function

## Description

Registers the hardware notification client driver and its callback functions with the class extension. This function should be invoked when the client driver is loaded and the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_initialize) routine is called for initialization.

## Parameters

### `Driver` [in]

Handle to the client drivers framework driver object.

### `RegistrationPacket` [in, out]

Pointer to the [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure that contains function pointers to the callback functions defined in the client driver implementation and required by the class extension.

### `RegistryPath` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path to the client driver’s registry key.

## Return value

Returns STATUS_SUCCESS if function succeeds. Returns STATUS_INVALID_PARAMETER if corresponding client driver can't be found. Otherwise, it returns one of the error status values defined in Ntstatus.h.

## Syntax

```cpp
FORCEINLINE NTSTATUS  HwNRegisterClient(
  _In_    WDFDRIVER                        Driver,
  _Inout_ PHWN_CLIENT_REGISTRATION_PACKET  RegistrationPacket,
  _In_    PUNICODE_STRING                  RegistryPath
);
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)