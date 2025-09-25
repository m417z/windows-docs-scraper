# HWN_CLIENT_SET_STATE callback

## Description

Implemented by the client driver to set hardware notification component state. It is invoked when a user wants to change the state of a driver.

## Parameters

### `Context` [in]

Pointer to the client driver's context information. This memory space is available for use by the client driver. It is allocated as part of the framework object context space by [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

### `Buffer` [in]

Buffer of *BufferLength* bytes containing a [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure including one or more [HWN_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structures that specify the hardware notifications to be set.

### `BufferLength` [in]

The size of *Buffer* in bytes.

### `BytesWritten` [out]

Pointer to a variable that indicates the number of bytes written by the function.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
HWN_CLIENT_SET_STATE HwnClientSetState;

NTSTATUS HwnClientSetState(
  _In_  PVOID  Context,
  _In_  PVOID  Buffer,
  _In_  ULONG  BufferLength,
  _Out_ PULONG BytesWritten
)
{ ... }

typedef HWN_CLIENT_SET_STATE *PHWN_CLIENT_SET_STATE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and then calling [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient).

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)