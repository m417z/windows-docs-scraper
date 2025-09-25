# HwNProcessAddDevicePreDeviceCreate function

## Description

Supplies the device prepare/release and entry/exit callbacks to the Windows Driver Foundation (WDF) for transitioning the device into different states. This function should be called by the client driver when the WDF invokes the driver’s [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine, but before creating the device object.

## Parameters

### `Driver` [in]

Handle to the client drivers framework driver object.

### `DeviceInit` [in]

A pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `FdoAttributes` [out]

Pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes of the client driver’s device object when it’s created.

## Return value

Returns STATUS_SUCCESS if function succeeds. Returns STATUS_INVALID_PARAMETER if corresponding client driver can't be found. Otherwise, it returns one of the error status values defined in Ntstatus.h.

## Syntax

```cpp
FORCEINLINE NTSTATUS  HwNProcessAddDevicePreDeviceCreate(
  _In_  WDFDRIVER               Driver,
  _In_  PWDFDEVICE_INIT         DeviceInit,
  _Out_ PWDF_OBJECT_ATTRIBUTES  FdoAttributes
);
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)