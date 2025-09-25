# VideoPortGetBusData function

## Description

The **VideoPortGetBusData** function returns bus-type-specific configuration information.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `BusDataType`

Specifies the type of bus configuration data to return. The value of this parameter can be **Cmos**, **EisaConfiguration**, or **PCIConfiguration**. However, additional types of bus configuration might be supported in the future. The upper bound on the types supported is always **MaximumBusDataType**.

### `SlotNumber`

Specifies the location of the device on the bus for a **Cmos** *BusDataType*; zero for all other bus types.

### `Buffer` [out]

Pointer to a buffer into which **VideoPortGetBusData** returns the configuration information. The contents of the buffer depend on the *BusDataType*, as follows:

* If **Cmos** is specified, the buffer contains the contents of the CMOS (bus number equals zero) or ECMOS (bus number equals one) locations, starting with the location specified for *SlotNumber*. A miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function can determine the number of the bus from the **SystemIoBusNumber** member of the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) input structure.
* If **EisaConfiguration** is specified, the buffer contains the [CM_EISA_SLOT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_slot_information) structure, followed by zero or more [CM_EISA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_function_information) structures for the specified slot.
* If **PCIConfiguration** is specified, the buffer contains the [PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85)) information for the specified slot.

### `Offset`

Specifies the offset, in bytes, into the PCI configuration space that should be retrieved If *BusDataType* is **PCIConfiguration**; otherwise zero. See **Remarks** for more information.

### `Length`

Specifies the length, in bytes, of *Buffer*.

## Return value

**VideoPortGetBusData** returns the number of bytes of configuration information it has written in *Buffer*. If the given *BusDataType* is not valid for the current platform, this function generally returns zero.

|Return code|Description|
|--- |--- |
|0|The PCI bus does not exist.|
|2|The PCI bus exists, but Buffer contains the value PCI_INVALID_VENDOR_ID at the PCI_COMMON_CONFIG VendorId member.|

## Remarks

To obtain only a part of the configuration information, the miniport driver should set *Offset* to the byte offset of the information needed, and set *Length* to the number of bytes of the information needed. For example, if only the command register is needed, set *Offset* to the offset of this register, and set *Length* to **sizeof**(USHORT).

The driver should call [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) rather than **VideoPortGetBusData** to retrieve its hardware resources.

## See also

[CM_EISA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_function_information)

[CM_EISA_SLOT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_eisa_slot_information)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85))

[PCI_SLOT_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_slot_number)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)