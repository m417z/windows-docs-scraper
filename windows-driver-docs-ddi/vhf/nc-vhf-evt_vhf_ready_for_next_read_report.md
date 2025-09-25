# EVT_VHF_READY_FOR_NEXT_READ_REPORT callback function

## Description

The HID source driver implements this event call back function to use its buffering scheme for HID Input Reports, and wants to get notified when the next report can be submitted to VHF.

## Parameters

### `VhfClientContext` [in]

Pointer to the HID source driver-defined context structure that the driver passed in the previous call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) to create the virtual HID device.

## Remarks

Virtual HID Framework (VHF) invokes this callback function to notify the HID source driver that it can submit a buffer to get the HID Input Report. After the callback is invoked, the HID source driver must call [VhfReadReportSubmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfreadreportsubmit) only once. If a portion of the HID Input Report is still pending, the driver must wait for VHF to invoke *EvtVhfReadyForNextReadReport* before the driver can call **VhfReadReportSubmit** again.

If the HID source driver does not implement this callback function, VHF uses a default buffering policy for HID Read (Input) Reports.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)