# _VIDEO_ACCESS_RANGE structure

## Description

The VIDEO_ACCESS_RANGE structure defines a device I/O port or memory range for the video adapter. Every miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function must set up an array of VIDEO_ACCESS_RANGE-type elements, called the *access ranges array*, for each video adapter the miniport driver supports.

For VGA-compatible miniport drivers, VIDEO_ACCESS_RANGE also defines an element in an array passed to [VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports) to enable or disable direct access to I/O ports by full-screen MS-DOS applications.

## Members

### `RangeStart`

Specifies the bus-relative base address of a memory or I/O port range for an element in the access ranges array passed to [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) or returned by [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges).

Specifies the bus-relative base address of an I/O port range for an array to be passed to [VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports).

### `RangeLength`

Specifies the number of I/O ports or size in bytes for the range.

### `RangeInIoSpace`

Specifies whether the range is in I/O space or in memory space. A value of **TRUE** (1) indicates that the range is in I/O space; a value of **FALSE** (0) indicates the range is in memory space.

### `RangeVisible`

Is ignored if the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function is setting up the access ranges array.

Is set to **TRUE** by VGA-compatible miniport drivers and passed to **VideoPortSetTrappedEmulatorPorts** to enable direct access to the I/O port range by a full-screen MS-DOS application. If set to **FALSE**, application-issued instructions continue to be trapped and forwarded to the miniport driver's *SvgaHwIoXxx* function for validation.

### `RangeShareable`

Is set to **TRUE** if the access range described by this element can be shared with another driver and/or device or to **FALSE** if the range cannot be shared.

Is ignored by VideoPortSetTrappedEmulatorPorts.

### `RangePassive`

Indicates whether the device actually uses the port. Values for this member are shown in the following table.

|Value|Meaning|
|--- |--- |
|VIDEO_RANGE_PASSIVE_DECODE|The device decodes the port but the driver does not use it.|
|VIDEO_RANGE_10_BIT_DECODE|The device decodes ten bits of the port address.|

## Remarks

The miniport driver must claim legacy resources in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) or [HwVidLegacyResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_legacyresources) function.

Otherwise, a miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function sets up the access ranges array for an adapter's PCI resources. It can use information returned by [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges). As an alternative, it can use information retrieved from the registry by calling [VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata) with a miniport driver-supplied [HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine) function or [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters) with a miniport driver-supplied [HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine) function. If calling these **VideoPort***Xxx* does not supply the bus-relative access range values, *HwVidFindAdapter* can set up access ranges elements using driver-supplied bus-relative default values.

### Claiming Access Ranges in the Registry

The miniport driver should call [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) with any access ranges obtained from **VideoPortGetDeviceData**, **VideoPortGetAccessRanges**, or supplied as defaults by the miniport driver. If **VideoPortVerifyAccessRanges** returns NO_ERROR for such an array of access ranges, the *HwVidFindAdapter* or *HwVidQueryDeviceCallback* function can then map the ranges with [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) and use the returned mapped logical addresses to access the adapter.

A successful call to [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) also claims the returned bus-relative access ranges in the registry for the caller. If the miniport driver modifies any of the returned values, it must call **VideoPortVerifyAccessRanges** with the full access range, including any unmodified elements. Each call to **VideoPortGetAccessRanges** or **VideoPortVerifyAccessRanges** for a particular video adapter overwrites the caller's claimed hardware resources in the registry.

A miniport driver must not attempt to use a range for which **VideoPortVerifyAccessRanges** or **VideoPortGetAccessRanges** does not return NO_ERROR.

### Mapping Access Ranges to Communicate with the Adapter

After a miniport driver has claimed resources in the registry for an adapter, it cannot use bus-relative addresses to access or configure the adapter, because the HAL can remap all bus-relative device addresses to [system space](https://learn.microsoft.com/windows-hardware/drivers/).

The miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function must call [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) to get mapped logical addresses for its access ranges. Only then can the miniport driver communicate with the video adapter by passing the returned mapped logical range addresses to **VideoPortRead/WritePort***Xxx* to access device memory in I/O space and/or **VideoPortRead/WriteRegister***Xxx* to access device memory in memory space.

### Determining whether an Access Range is Sharable

Follow these guidelines to determine whether an access range can be shared:

* If the range of memory or I/O ports should be "owned" by this driver, and/or access to this range by any other driver can cause a problem, set **RangeSharable** to **FALSE**.
* If the range can be shared with a cooperating device driver, set **RangeSharable** to **TRUE**.

SVGA miniport drivers that implement all VGA functionality (declared in the registry as **VgaCompatible** set to one) should claim their access ranges as unsharable so the system VGA driver will not be loaded. On the other hand, miniport drivers for adapters such as the S3 or the XGA, which set **VgaCompatible** to zero in the registry, should claim all the resources they share with the system VGA driver as sharable.

However, miniport drivers for cards that work with a pass-through IOCTL and that can be connected to any VGA or SVGA card should not be using any system VGA ports or memory ranges. If they do, such a driver should not attempt to claim any of the VGA access ranges in the registry. Attempts to claim VGA resources by such a miniport driver are likely to cause a resource conflict because the driver of any SVGA card in the machine will have claimed these access ranges as unsharable.

### Passing I/O Port Range Elements to VideoPortSetTrappedEmulatorPorts

All VIDEO_ACCESS_RANGE-type array elements describing I/O port ranges are assumed to be invisible, unless a VGA-compatible miniport driver in an x86-based machine explicitly resets the **RangeVisible** member(s) to **TRUE** and calls [VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports) to enable one or more I/O port ranges. **VideoPortSetTrappedEmulatorPorts** ignores the **RangeSharable** members of the input array.

In an array of VIDEO_ACCESS_RANGE-type elements passed to **VideoPortSetTrappedEmulatorPorts**, the value of each element's **RangeVisible** member determines whether the given I/O port(s) can be accessed directly by the VDM (MS-DOS application running in full-screen on an x86-based machine) or whether such an application-issued I/O stream is trapped and forwarded to a miniport driver-supplied *SvgaHwIoPortXxx* function for validation first.

## See also

[DriverEntry of Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-video-miniport-driver)

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)

[VideoPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinitialize)

[VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)