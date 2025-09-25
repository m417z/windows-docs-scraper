## Description

The **VIDEO_CHILD_TYPE** enumeration specifies the type of child device that is attached to a video device.

## Constants

### `Monitor`

Identifies a device that might have a DDC2 compliant EDID data structure. If the video miniport detects such a device, it should extract the EDID from the monitor and put that in the paged buffer provided by *videoprt.sys* in the callback to [**PVIDEO_HW_GET_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) and return this type in the **VideoChildType** parameter of that call. This EDID, if available, will be written to the registry. If the EDID is not available, nothing should be put in the buffer.

### `NonPrimaryChip`

Identifies another VGA chip on the video board that is not the primary VGA chip. This type is to be used if and only if the miniport detects more than one VGA chip on the board. Such an identifier will cause the *videoprt.sys* to create another DEVICE_EXTENSION and associated HW_DEVICE_EXTENSION to be associated with the chip so identified.

### `VideoChip`

Primary video chip on the video card.

### `Other`

Identifies some other video device attached to the video card. If the miniport detects such a device, it is to put a wide char string (WSTR) into the paged buffer provided by the videoprt.sys which is the PNP hardware identifier of the device. This string will be used to create a value of that name in the registry.