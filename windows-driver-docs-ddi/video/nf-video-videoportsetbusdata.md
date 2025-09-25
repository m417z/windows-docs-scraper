# VideoPortSetBusData function

## Description

The **VideoPortSetBusData** function sets bus-configuration data for an adapter on a dynamically configurable I/O bus with a published, standard interface.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `BusDataType`

Specifies the type of bus data to be set. Currently, its value can be one of **Cmos**, **EisaConfiguration**, or **PCIConfiguration**. However, additional types of standardized, dynamically configurable buses might be supported in the future. The upper bound on the bus types supported is always **MaximumBusDataType**.

### `SlotNumber`

For a *BusDataType* value of **Cmos**, specifies the location of the device on the bus. This parameter should be zero for all other bus types.

### `Buffer` [in]

Pointer to a caller-supplied storage area with configuration information specific to *BusDataType*.

When **PCIConfiguration** is specified, the buffer contains some or all of the [PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85)) information for the given *SlotNumber*. The specified *Offset* and *Length* determine how much information is supplied.

### `Offset`

Specifies the byte offset within the PCI_COMMON_CONFIG structure at which the caller-supplied configuration values begin. A miniport driver can use PCI_COMMON_HDR_LENGTH to specify the offset of the device-specific area in PCI_COMMON_CONFIG.

### `Length`

Specifies the number of bytes in *Buffer*.

## Return value

**VideoPortSetBusData** returns the number of bytes of data successfully set for the given *SlotNumber*. If the given *BusDataType* is not valid for the current platform or if the supplied information is invalid, **VideoPortSetBusData** returns zero.

## Remarks

Miniport drivers of adapters on a PCI bus seldom call **VideoPortSetBusData**, unless unusual circumstances or the nature of a particular driver's video adapter requires such a call.

For example, a miniport driver might call **VideoPortSetBusData** to clear a bit in the PCI status register if its adapter signals a target abort during initialization. If a PCI video adapter must be configured with device-specific data, its driver also calls this function. In either case, such a driver is then likely to call [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) with a *RequestedResources* pointer to a driver-supplied array of resource descriptors.

**VideoPortSetBusData** cannot be called from a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) functions, or from [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc), or from a callback to [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution).

## See also

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85))

[PCI_SLOT_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_slot_number)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata)