# EVT_VHF_CLEANUP callback function

## Description

The HID source driver implements this event callback to free resources that might the driver allocated to the virtual HID device.

## Parameters

### `VhfClientContext` [in]

Pointer to the HID source driver-defined context structure that the driver passed in the previous call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) to create the virtual HID device.

## Remarks

To delete the virtual HID device, the HID source driver calls [VhfDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfdelete). That call causes Virtual HID Framework (VHF) to invoke the previously-registered *EvtVhfCleanup*, if the callback function is implemented by the HID source driver. When the driver calls VhfDelete with *Wait* set to TRUE, *EvtVhfCleanup* gets called before **VhfDelete** returns. If *Wait* is FALSE, it might get called any time after **VhfDelete** is called that is before or after **VhfDelete** returns.

The call gives the HID source driver an opportunity to free resources allocated for the virtual HID device when that device is deleted.

The HID source driver must not use the VHFHANDLE for the virtual HID device (created by [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate)) after this callback function returns. Before invoking this callback function, VHF makes sure that there are no asynchronous operations pending.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)