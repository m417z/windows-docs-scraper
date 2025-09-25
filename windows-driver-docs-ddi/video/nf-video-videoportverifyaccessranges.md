# VideoPortVerifyAccessRanges function

## Description

The **VideoPortVerifyAccessRanges** function checks the registry for whether another driver has already claimed ownership of the specified bus-relative access ranges and any other hardware resources specified in the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure. If not, this function claims the given resources for the caller.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `NumAccessRanges`

Specifies the number of elements in the *AccessRanges* array, or zero.

### `AccessRanges` [in, optional]

Pointer to the miniport driver's access ranges array, or **NULL**. Each [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)-type element in this array specifies a bus-relative range of device memory, I/O ports, or register addresses for the adapter.

## Return value

**VideoPortVerifyAccessRanges** returns one of the following values:

|Return code|Description|
|--- |--- |
|ERROR_INVALID_PARAMETER|An error occurred or a conflict was found; that is, another driver has already claimed one or more of the given hardware resources for its device.|
|NO_ERROR|The given AccessRanges are valid and have been claimed for use by the caller.|

## Remarks

Every video miniport driver either must call **VideoPortVerifyAccessRanges**, or use access ranges returned by [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) before attempting to access a video adapter during the driver (and system) initialization process.

**VideoPortVerifyAccessRanges** can be called only by a miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function.

Every video miniport driver must define the bus-relative access ranges for its device, either as statically allocated memory in the driver's header file or code or on the stack. Most miniport drivers set up their video access ranges on the stack, except for those that use PC standard address ranges for video memory, such as VGA-compatible SVGA miniport drivers.

The *HwVidFindAdapter* function should try to obtain bus-relative access range information by calling [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges), or by checking the registry through calls to [VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata) or [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters). If [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) cannot get this information, the miniport driver should have a set of bus-relative default values for access ranges.

If a miniport driver's access ranges are externally configurable, the installation program sets up access ranges for the adapter in the registry. Such a miniport driver's *HwVidFindAdapter* function can call **VideoPortGetRegistryParameters** with a miniport driver-supplied [HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine) function that processes information retrieved from the registry.

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) must not pass any access range addresses to [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) unless it calls **VideoPortVerifyAccessRanges** or [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) first and the respective function returns NO_ERROR.

**VideoPortVerifyAccessRanges** can be called again if the initial *AccessRanges* specification or value in the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info), such as an interrupt vector, causes it to return an ERROR_*XXX* indicating that another driver has already claimed the resource(s).

If **VideoPortVerifyAccessRanges** returns NO_ERROR, a subsequent call for the same adapter overwrites the miniport driver's claim on resources for that adapter in the registry.

Note that a miniport driver cannot communicate with its video adapter, except by using mapped addresses returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) with the **VideoPortRead/Write***Xxx* functions.

If the [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function claims bus-relative access ranges and possibly other hardware resources for an adapter but then determines that it does not support the adapter, the miniport driver must relinquish its claims on hardware resources in the registry by calling **VideoPortVerifyAccessRanges** or [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) with *NumAccessRanges* set to zero and *AccessRanges* set to **NULL**.

To relinquish claims on a subset of claimed access ranges that the miniport driver is no longer using, do the following:

1. Modify the *AccessRanges* specification for the adapter so that each element describing a range to be released still has **RangeStart** set to the bus-relative base of a claimed range, but **RangeLength** reset to zero.
2. Call **VideoPortVerifyAccessRanges** with this modified *AccessRanges* array.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)