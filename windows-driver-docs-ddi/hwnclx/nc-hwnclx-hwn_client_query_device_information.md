# HWN_CLIENT_QUERY_DEVICE_INFORMATION callback

## Description

Implemented by the client driver to retrieve hardware notification component attributes.

## Parameters

### `Context` [in]

Pointer to the client driver's context information. This memory space is available for use by the client driver. It is allocated as part of the framework object context space by [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

### `Information` [out]

Pointer to a buffer that receives the controller’s attributes.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
HWN_CLIENT_QUERY_DEVICE_INFORMATION HwnClientQueryDeviceInformation;

NTSTATUS HwnClientQueryDeviceInformation(
  _In_  PVOID                      Context,
  _Out_ PCLIENT_DEVICE_INFORMATION Information
)
{ ... }

typedef HWN_CLIENT_QUERY_DEVICE_INFORMATION PHWN_CLIENT_QUERY_DEVICE_INFORMATION;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and then calling [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient).

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)