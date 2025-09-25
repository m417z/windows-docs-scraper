# HwNProcessAddDevicePostDeviceCreate function

## Description

 Creates I/O queues. It should be called after the client driver’s [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function is invoked and the device object has been created.

## Parameters

### `Driver` [in]

Handle to the client drivers framework driver object.

### `Device` [in]

Handle to the framework device object.

### `DeviceGuid` [in]

Pointer to the GUID for the client driver. Valid values are defined in Hwn.h, which ships with Window SDK.

## Return value

Returns STATUS_SUCCESS if function succeeds. Returns STATUS_INVALID_PARAMETER if corresponding client driver can't be found. Otherwise, it returns one of the error status values defined in Ntstatus.h.

## Syntax

```cpp
FORCEINLINE NTSTATUS  HwNProcessAddDevicePostDeviceCreate(
  _In_ WDFDRIVER  Driver,
  _In_ WDFDEVICE  Device,
  _In_ LPGUID     DeviceGuid
);
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)