# VhfReadReportSubmit function

## Description

The HID source driver calls this method to submit a HID Read (Input) Report to Virtual HID Framework (VHF).

## Parameters

### `VhfHandle` [in]

A handle to a virtual HID device that your HID source driver received in the previous call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate).

### `HidTransferPacket` [in]

A pointer to a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure that describes the HID report.

## Return value

If the **VhfReadReportSubmit** call succeeds, the method returns STATUS_SUCCESS. Otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)  value.

## Remarks

The HID source driver can choose to implement its buffering policy or let Virtual HID Framework (VHF) handle buffering.

If the driver uses its own buffering policy, then it must implement and register an [EvtVhfReadyForNextReadReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_ready_for_next_read_report) callback function in its call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate). It must call *VhfReadReportSubmit* only once after VHF has invoked *EvtVhfReadyForNextReadReport*. After the callback has been invoked, the driver can reuse the transfer buffer pointed to by *HidTransferPacket*. The driver must wait for the next time that VHF invokes *EvtVhfReadyForNextReadReport* before calling this method again.

If the HID source driver does not implement the [EvtVhfReadyForNextReadReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_ready_for_next_read_report) callback, then there are no restrictions on calling this method. VHF uses the default buffering policy. The driver can reuse the transfer buffer after the call returns.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)