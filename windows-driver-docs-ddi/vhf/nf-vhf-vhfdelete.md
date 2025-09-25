# VhfDelete function

## Description

The HID Source device driver calls this method to delete a VHF device.

## Parameters

### `VhfHandle` [in]

A handle to a virtual HID device that your HID source driver received in the previous call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate).

### `Wait` [in]

TRUE to return synchronously after deleting a device. In this case, Virtual HID Framework (VHF) does not return until the device is reported as missing to PnP Manager and [EvtVhfCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_cleanup) callback function returns.

FALSE is reserved and should not be passed. See Remarks for more information.

## Remarks

The HID source driver must stop initiating new requests for the Virtual HID Framework (VHF) just before calling **VhfDelete**.

To call **VhfDelete** synchronously, call it at PASSIVE_LEVEL with the *Wait* parameter set to TRUE. In this case, it returns synchronously after completing the deletion. If the HID source driver has registered an [EvtVhfCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_cleanup) callback function with VHF, it invokes that callback before **VhfDelete** returns. The function might be invoked on the same thread.

**VhfDelete** cannot be called asynchronously (*Wait* parameter set to FALSE) or at any IRQL higher than PASSIVE_LEVEL. Doing so may result in undefined behavior.

There are no restrictions on when a KMDF driver should call this function. It is recommended to call it from a function matching the [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) call. For example, if **VhfCreate** is called from [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add), then call **VhfDelete** synchronously from *EvtDeviceCleanupCallback*. **VhfDelete** may be called on a VHFHANDLE without having previously called **VhfStart**.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)