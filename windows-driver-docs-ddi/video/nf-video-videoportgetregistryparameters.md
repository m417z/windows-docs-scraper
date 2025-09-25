# VideoPortGetRegistryParameters function

## Description

The **VideoPortGetRegistryParameters** function retrieves device-specific configuration information under the **adapter** key in the registry at startup.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `ParameterName` [in]

Pointer to a NULL-terminated Unicode string that names the value entry to be retrieved from the registry. See the **Remarks** section for more information.

### `IsParameterFileName`

If the value is **TRUE**, the data value normally returned is treated as a file name. In that case, the buffered contents of that file are returned, rather than the parameter itself.

### `GetRegistryRoutine`

Pointer to the miniport driver's [HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine) function.

### `Context`

Pointer to a caller-determined context parameter to be passed to the *CallbackRoutine*, typically the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) buffer.

## Return value

**VideoPortGetRegistryParameters** returns NO_ERROR if it successfully collected the requested information and called the miniport driver's *HwVidQueryNamedValueCallback* function; otherwise returns ERROR_INVALID_PARAMETER.

## Remarks

**VideoPortGetRegistryParameters** cannot be called from a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) functions, or from [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc), or from a callback to [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution).

For Windows XP and later operating system versions, the *ParameterName* parameter can contain a path that exactly references a value name one or more levels below the **adapter** key. For example, the string "SubKey1\Value1" can be used to obtain the value entry for the Value1 value number under the SubKey1 subkey.

The registry key from which **VideoPortGetRegistryParameters** retrieves configuration information cannot contain any information about the corresponding display driver, because miniport driver [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) functions execute before any display driver is loaded.

Miniport drivers should not query configuration information stored in the **DefaultSettings** entries, which may not be supported in later versions of the operating system.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortFlushRegistry](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportflushregistry)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortSetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsetregistryparameters)