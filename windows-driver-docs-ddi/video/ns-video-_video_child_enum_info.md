# _VIDEO_CHILD_ENUM_INFO structure

## Description

Describes the child device to be enumerated by the miniport driver. All members are set by the video port driver.

## Members

### `Size`

The size in bytes of this structure.

### `ChildDescriptorSize`

The size in bytes of the buffer to which *pChildDescriptor* points. The video port driver allocates this buffer to be large enough to accommodate a DDC2-compliant EDID structure.

### `ChildIndex`

The index of the child device for which the system is requesting information. This member is used to enumerate devices that are not enumerated by ACPI or other operating system components. If **ChildIndex** is set to zero, the driver should use the value specified in **ACPIHwId** as the ID of the device being enumerated.

### `ACPIHwId`

The identifier returned by the ACPI BIOS that represents the child device being enumerated. The miniport driver should use this member only if **ChildIndex** is zero.

The **ACPIHwId** returned by the firmware must match the value returned in *UId* by the miniport driver. The System BIOS manufacturer and the graphics IHV must synchronize these IDs.

### `ChildHwDeviceExtension`

A pointer to a device extension specific to this child device. This member is valid only if the miniport driver filled the **ChildHwDeviceExtensionSize** member of VIDEO_HW_INITIALIZATION_DATA with a value other than zero.

## Remarks

One parameter of the *HwVidGetVideoChildDescriptor* function is an instance of a VIDEO_CHILD_ENUM_INFO structure.

The ACPI_METHOD_DISPLAY_DOD alias, defined in Dispmprt.h, represents the method used to enumerate the devices attached to the display adapter. This method is required if the integrated device controller supports switching of output devices.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)