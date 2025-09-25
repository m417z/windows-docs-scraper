# PMINIPORT_GET_REGISTRY_ROUTINE callback function

## Description

*HwVidQueryNamedValueCallback* processes the specified data retrieved from the registry.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `Context`

Pointer to a driver-determined context specified as input to the [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters) function.

### `ValueName`

Pointer to a NULL-terminated Unicode string naming the entry.

### `ValueData`

Pointer to the buffered data associated with *ValueName*, supplied by **VideoPortGetRegistryParameters**.

### `ValueLength`

Specifies the size in bytes of the buffer at *ValueData*.

## Return value

*HwVidQueryNamedValueCallback* returns the status of the operation.

## Remarks

*HwVidQueryNamedValueCallback* is an optional miniport driver function passed in a call to [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters).

**VideoPortGetRegistryParameters** calls *HwVidQueryNamedValueCallback* after collecting available configuration information about the given *ValueName* in the **adapter** key of the registry.

*HwVidFindAdapter* or [HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize) can call **VideoPortGetRegistryParameters** with a driver-supplied *HwVidQueryNamedValueCallback* function, pointers to the device extension and any driver-supplied context data (which can be the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) buffer), and a pointer to a Unicode string naming the value to be retrieved from the registry.

*HwVidFindAdapter* or *HwVidInitialize* can set **VideoPortGetRegistryParameters**'s *IsFileNameParameter* argument to **TRUE** if the driver-supplied Unicode string is a named registry entry whose value is a file name. For this specification, the returned data will be the contents of the named file.

When **VideoPortGetRegistryParameters** calls the *HwVidQueryNamedValueCallback* function, it processes whatever configuration data is made available. For example, *HwVidQueryNamedValueCallback* might use retrieved data to determine the miniport driver's access ranges and to set up its emulator access ranges (if any), interrupt vector or interrupt IRQL (if any), and so forth in the VIDEO_PORT_CONFIG_INFO buffer, as well as in the miniport driver's device extension, before returning control to the *HwVidFindAdapter* function.

*HwVidInitialize* might also call **VideoPortGetRegistryParameters** with *IsFileNameParameter* set to **TRUE** so that the miniport driver-supplied *HwVidQueryNamedValueCallback* function could use the buffered contents of a named file to set up microcode on the adapter.

The returned *ValueData* is on the stack, so it can be referenced locally. *HwVidQueryNamedValueCallback* can store some or all of the returned information for use by other miniport driver functions in the input *HwDeviceExtension* or use the input *Context* as a pointer to a location where the data can be stored.

*HwVidQueryNamedValueCallback* should be made pageable.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)

[VideoPortSetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsetregistryparameters)