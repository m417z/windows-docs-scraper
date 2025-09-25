# HWN_CLIENT_START_DEVICE callback

## Description

Implemented by the client driver to start the hardware notification component. It is invoked as a result of a call to [EVT_WDF_DEVICE_D0_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry).

## Parameters

### `Context` [in]

Pointer to the client driver's context information. This memory space is available for use by the client driver. It is allocated as part of the framework object context space by [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
HWN_CLIENT_START_DEVICE HwnClientStartDevice;

NTSTATUS HwnClientStartDevice(
  _In_ PVOID Context
)
{ ... }

typedef HWN_CLIENT_START_DEVICE *PHWN_CLIENT_START_DEVICE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and then calling [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient).

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)