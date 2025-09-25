# VHF_CONFIG_INIT function

## Description

Use the **VHF_CONFIG_INIT** function to initialize the required members of the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure allocated by the HID source driver.

## Syntax

```cpp
FORCEINLINE
VOID
VHF_CONFIG_INIT(
    _Out_
        PVHF_CONFIG     Config,
#ifdef _KERNEL_MODE
    _In_
        PDEVICE_OBJECT  DeviceObject,
#else
    _In_
        HANDLE          FileHandle,
#endif
    _In_
        USHORT          ReportDescriptorLength,
    _In_reads_bytes_(ReportDescriptorLength)
        PUCHAR          ReportDescriptor
    )
```

## Parameters

### `Config` [out]

A pointer to the [VHF_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config) structure to initialize.

### `DeviceObject` [in]

A pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure for the HID source driver. Get that pointer by calling [WdfDeviceWdmGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetdeviceobject) and passing the WDFDEVICE handle that the driver received in the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call.

A user-mode driver would instead provide a *FileHandle*. For more info, see [**VHF_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/ns-vhf-_vhf_config).

### `ReportDescriptorLength` [in]

The length of the HID Report Descriptor contained in a buffer pointer by *ReportDescriptor*.

### `ReportDescriptor`

A pointer to a HID source driver-allocated buffer that contains the HID Report Descriptor.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)