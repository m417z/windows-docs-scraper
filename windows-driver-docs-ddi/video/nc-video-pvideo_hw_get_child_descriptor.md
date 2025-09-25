# PVIDEO_HW_GET_CHILD_DESCRIPTOR callback function

## Description

*HwVidGetVideoChildDescriptor* returns a descriptor, a type, and an identification number for a particular child device of the display adapter.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `ChildEnumInfo` [in]

Is a [VIDEO_CHILD_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_enum_info) structure that describes the device being enumerated.

### `VideoChildType` [out]

Pointer to a location in which the miniport driver returns the type of child being enumerated. This member can be one of the following from the VIDEO_CHILD_TYPE enumeration:

| **Value** | **Meaning** |
|:--|:--|
| **Monitor** | The child device is a monitor. If the miniport driver detects that the monitor has a DDC2-compliant [EDID](https://learn.microsoft.com/windows-hardware/drivers/) structure associated with it, the miniport driver should extract the EDID information from the monitor and return it in the buffer to which pChildDescriptor points. The miniport driver can more easily obtain the EDID from the monitor by calling [VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper). <br>If the detected monitor is not DDC2-compliant, the miniport driver should not return anything in pChildDescriptor. |
| **NonPrimaryChip** | Is reserved for system use. |
| **VideoChip** | The child device is the graphics chip.<br>The miniport driver should return this type when ChildEnumInfo.ChildIndex is DISPLAY_ADAPTER_HW_ID. The miniport driver should not return anything in pChildDescriptor. |
| **Other** | The child device has a separate device driver associated with it.<br>The miniport driver should return the device's PnP hardware identifier as a Unicode string in the buffer to which pChildDescriptor points. This string must match the [device ID](https://learn.microsoft.com/windows-hardware/drivers/) specified in the driver's INF file. It will be used by the operating system as the hardware ID for this device. |

### `pChildDescriptor` [out]

Pointer to a buffer in which the miniport driver can return data that identifies the device. The information returned depends on the child type specified in *VideoChildType*. The size of this buffer is specified by the video port driver in the **ChildDescriptorSize** member of [VIDEO_CHILD_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_enum_info).

### `UId` [out]

Pointer to the location in which the miniport driver returns a unique 32-bit [device ID](https://learn.microsoft.com/windows-hardware/drivers/) for this device. The miniport driver should set *UId* to be DISPLAY_ADAPTER_HW_ID when the device is the actual display adapter.

### `pUnused` [out]

Is unused and must be set to zero.

## Return value

*HwVidGetVideoChildDescriptor* returns one of the following values:

|Return code|Description|
|--- |--- |
|VIDEO_ENUM_INVALID_DEVICE|Call again. The miniport driver could not enumerate the child device identified in ChildEnumInfo but there are more devices to be enumerated.|
|VIDEO_ENUM_MORE_DEVICES|A new child device is enumerated. The video port will call HwVidGetVideoChildDescriptor again in this case.|
|VIDEO_ENUM_NO_MORE_DEVICES|The miniport driver could not enumerate the child device identified in ChildEnumInfo. Stop enumeration. There are no more devices to be enumerated.|

## Remarks

By default, *HwVidGetVideoChildDescriptor* is not called until after the device is started by [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter). To allow the enumeration of a device's children before the device is started, set the **AllowEarlyEnumeration** member of [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data). When **AllowEarlyEnumeration** is set, *HwVidGetVideoChildDescriptor* can be called at any time.

*HwVidGetVideoChildDescriptor* should do the following:

* Determine the type of the child device based on the data supplied in *ChildEnumInfo*, and return this type in *VideoChildType*.
* Fill in the buffer to which *pChildDescriptor* points with the appropriate data, depending on the value of *VideoChildType*.
* Write a 32-bit value in *UId* that uniquely identifies the child device being enumerated. The video port driver will pass this handle back to the miniport driver for operations such as power management.

*HwVidGetVideoChildDescriptor* should be made pageable.

## See also

[HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get)

[HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set)

[VIDEO_CHILD_ENUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_enum_info)

[VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper)

[VideoPortEnumerateChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportenumeratechildren)