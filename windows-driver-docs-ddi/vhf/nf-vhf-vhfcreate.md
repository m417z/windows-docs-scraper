# VhfCreate function

## Description

The HID source driver calls this method to create a virtual HID device.

## Parameters

### `VhfConfig` [in]

A pointer to a [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure.

### `VhfHandle` [out]

A handle to the new virtual HID device.

## Return value

If the **VhfCreate** call succeeds, the method returns STATUS_SUCCESS. Otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)  value.

## Remarks

 This method returns synchronously after validating the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure and creating a virtual HID device. The virtual HID device is only reported to PnP. The initialization, installation, and starting of the device may not complete before this method returns.

A Kernel-Mode Driver Framework (KMDF) driver can call **VhfCreate** at any point after successfully creating its own device object by calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). The driver can do so in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add), [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware), [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry), [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init).

VHF does not invoke any callback functions that are specified in [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) until the HID source driver calls [VhfStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfstart).

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)