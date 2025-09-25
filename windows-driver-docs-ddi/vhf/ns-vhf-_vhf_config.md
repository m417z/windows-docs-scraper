# _VHF_CONFIG structure

## Description

Contains initial configuration information that is provided by the HID source driver when it calls [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate) to create a virtual HID device.

## Syntax

```cpp
typedef struct _VHF_CONFIG {

    ULONG                               Size;

    PVOID                               VhfClientContext;

    ULONG                               OperationContextSize;

#ifdef _KERNEL_MODE
    PDEVICE_OBJECT                      DeviceObject;
#else
    HANDLE                              FileHandle;
#endif

    USHORT                              VendorID;
    USHORT                              ProductID;
    USHORT                              VersionNumber;

    GUID                                ContainerID;

    USHORT                              InstanceIDLength;
    _Field_size_bytes_full_(InstanceIDLength)
    PWSTR                               InstanceID;

    USHORT                              ReportDescriptorLength;
    _Field_size_full_(ReportDescriptorLength)
    PUCHAR                              ReportDescriptor;

    PEVT_VHF_READY_FOR_NEXT_READ_REPORT EvtVhfReadyForNextReadReport;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationGetFeature;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationSetFeature;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationWriteReport;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationGetInputReport;
    PEVT_VHF_CLEANUP                    EvtVhfCleanup;

    USHORT                              HardwareIDsLength;
    _Field_size_bytes_full_(HardwareIDsLength)
    PWSTR                               HardwareIDs;

} VHF_CONFIG, *PVHF_CONFIG;
```

## Members

### `Size`

Required. Size of this structure initialized by [VHF_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhf_config_init).

### `VhfClientContext`

Optional. An opaque pointer to HID source driver-allocated memory that the Virtual HID Framework (VHF) passes when it invokes those callback functions.

### `OperationContextSize`

Optional. Size of the buffer that VHF must allocate for an asynchronous operation started by [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation). If non-zero, VHF allocates a buffer of this size and passes a pointer to that buffer in the *VhfOperationContext* parameter each time it invokes *EvtVhfAsyncOperation* to start a new operation.

### `DeviceObject`

Required for kernel-mode drivers. A pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure for the HID source driver. Get that pointer by calling [WdfDeviceWdmGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetdeviceobject) and passing the WDFDEVICE handle that the driver received in the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call.

### `FileHandle`

Required for user-mode drivers. A file handle obtained by calling [**WdfIoTargetWdmGetTargetFileHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetwdmgettargetfilehandle).
To open a WDFIOTARGET, a user-mode (UMDF) VHF source driver should call [**WdfIoTargetOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) with **OpenParams.Type** set
to **WdfIoTargetOpenLocalTargetByFile**.

### `VendorID`

Optional. Vendor ID of the virtual HID device to be created.

### `ProductID`

Optional. Product ID of the virtual HID device to be created.

### `VersionNumber`

Optional. Version number of the virtual HID device to be created.

### `ContainerID`

Optional. Container ID of the virtual HID device to be created.

### `InstanceIDLength`

### `InstanceID`

### `ReportDescriptorLength`

Required. The length of the HID Report Descriptor contained in a buffer pointed by **ReportDescriptor**.

### `ReportDescriptor`

Required. A pointer to a HID source driver-allocated buffer that contains the HID Report Descriptor.

### `EvtVhfReadyForNextReadReport`

Optional. A pointer to an [EvtVhfReadyForNextReadReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_ready_for_next_read_report) callback. The HID source driver must implement and register this callback function if it wants to handle the buffering policy for submitting HID Input Reports. If this callback is specified, VHF does not buffer those reports. The HID source driver should submit one report by calling [VhfReadReportSubmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfreadreportsubmit), each time VHF invokes *EvtVhfReadyForNextReadReport*.

### `EvtVhfAsyncOperationGetFeature`

Optional. A pointer to an [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation) callback. The HID source driver must implement and register this callback function if it wants to a get a HID Feature Report associated with a [Top-Level Collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) from the HID class driver pair.
The driver can get a Feature Report only if the Report Descriptor declares it.

### `EvtVhfAsyncOperationSetFeature`

Optional. A pointer to an [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation) callback. The HID source driver must implement and register this callback function if it wants to a send a HID Feature Report associated with a [Top-Level Collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) to the HID class driver pair. The driver can set a Feature Report only if the Report Descriptor declares it.

### `EvtVhfAsyncOperationWriteReport`

Optional. A pointer to an [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation) callback. The HID source driver must implement and register this callback function if it wants to a support HID Output Reports and send them to the HID class driver pair.

### `EvtVhfAsyncOperationGetInputReport`

Optional. A pointer to an [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation) callback. The HID source driver must implement and register this callback function if it wants to support on-demand query for Input Reports.

### `EvtVhfCleanup`

Optional. A pointer to a [EvtVhfCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_cleanup) callback. The HID source driver can implement and register this callback function if it wants to free the allocated resources for the virtual HID device.

### `HardwareIDsLength`

### `HardwareIDs`

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)