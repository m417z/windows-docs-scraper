# HWN_CLIENT_INITIALIZE_DEVICE callback

## Description

Implemented by the client driver and is invoked as a result of a call to [EVT_WDF_DEVICE_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

## Parameters

### `Device` [in]

Handle to the client drivers framework device object.

### `Context` [in]

Pointer to the client driver's context information. This memory space is available for use by the client driver. It is allocated as part of the framework object context space by [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

### `ResourcesRaw` [in]

Handle to a framework resource-list object that identifies the raw hardware resources that the Plug and Play manager has assigned to the device.

### `ResourcesTranslated` [in]

Handle to a framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
HWN_CLIENT_INITIALIZE_DEVICE HwnClientInitializeDevice;

NTSTATUS HwnClientInitializeDevice(
  _In_ WDFDEVICE    Device,
  _In_ PVOID        Context,
  _In_ WDFCMRESLIST ResourcesRaw,
  _In_ WDFCMRESLIST ResourcesTranslated
)
{ ... }

typedef HWN_CLIENT_INITIALIZE_DEVICE *PHWN_CLIENT_INITIALIZE_DEVICE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and then calling [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient).

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)