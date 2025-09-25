# EVT_VHF_ASYNC_OPERATION callback function

## Description

The HID source driver implements this event callback if it wants to support one of the four asynchronous operation to get and set HID reports.

## Parameters

### `VhfClientContext` [in]

An opaque pointer to a HID source driver-defined buffer that the driver passed in the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure supplied to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) to create the virtual HID device.

### `VhfOperationHandle` [in]

An opaque handle that uniquely identifies this asynchronous operation.

### `VhfOperationContext` [in, optional]

Pointer to a buffer that can be used by the HID source driver for servicing the operation. Size of the buffer is specified by the HID source driver in the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure supplied to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate).

### `HidTransferPacket` [in]

A pointer to a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure. Contains information about a HID Report and is used by the HID source driver and the HID class/mini driver pair for I/O requests to get or set a report.

## Remarks

There are four types of asynchronous operations that your HID source driver can support: **GetFeature**, **SetFeature**, **WriteReport**, **GetInputReport**.

**Note** Those operations are analogous to [IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature), [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature), [IOCTL_HID_WRITE_REPORT](https://learn.microsoft.com/previous-versions/hh439646(v=vs.85)), [IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report) requests that a HID transport minidriver implements.

To support such an operation, the HID source driver must implement an *EvtVhfAsyncOperation* callback function and register it with the Virtual HID Framework (VHF) in the driver's call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) function after calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For example, for **GetFeature**, the driver must implement *EvtVhfAsyncOperation* and set the **EvtVhfAsyncOperationGetFeature** member of the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) to a function pointer of the implemented function.

When VHF gets a request that sets or queries a HID Report, VHF invokes the previously-registered *EvtVhfAsyncOperation* callback function and an asynchronous operation starts. Each operation is identified by a VHFOPERATIONHANDLE handle that is set by VHF. If the driver specified a non-zero value in the **OperationContextSize** member of the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) during initialization, VHF allocates a buffer of that size and passes a pointer to that buffer in the *VhfOperationContext* parameter when it invokes *EvtVhfAsyncOperation*.

*HidTransferPacket* is the transfer buffer for this operation that points to a VHF-allocated structure containing HID Report-specific details. For example, if the operation is **GetFeature**, upon completion the buffer is filled by the HID source driver with the requested HID Feature Report.

When the operation is complete, HID source calls [VhfAsyncOperationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfasyncoperationcomplete) to report the completion status.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)