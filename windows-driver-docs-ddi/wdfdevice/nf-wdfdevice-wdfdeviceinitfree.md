# WdfDeviceInitFree function

## Description

[Applies to KMDF only]

The **WdfDeviceInitFree** method deallocates a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

If your driver receives a WDFDEVICE_INIT structure from a call to [WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate) or [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate), and if the driver subsequently encounters an error when it calls a [device object initialization method](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) or [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), the driver must call **WdfDeviceInitFree**.

Your driver must not call **WdfDeviceInitFree** after it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) successfully.

Your driver does not need to call **WdfDeviceInitFree** if it received the WDFDEVICE_INIT structure as input to its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, because the framework deletes the structure after the callback function returns.

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example calls **WdfDeviceInitFree** if a call to [WdfPdoInitAssignRawDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassignrawdevice) fails.

```cpp
NTSTATUS  status;

status = WdfPdoInitAssignRawDevice(
                                   pDeviceInit,
                                   &GUID_DEVCLASS_KEYBOARD
                                   );
if (!NT_SUCCESS(status)) {
    WdfDeviceInitFree(pDeviceInit);
    pDeviceInit = NULL;
    return STATUS;
}
```

## See also

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)