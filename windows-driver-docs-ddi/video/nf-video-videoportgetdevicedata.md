# VideoPortGetDeviceData function

## Description

The **VideoPortGetDeviceData** function retrieves system-detected configuration information from the **..\Machine\Hardware\Description** tree in the registry. This information is bus-specific or adapter-specific and stored in the registry by the system loader or the HAL.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `DeviceDataType`

Specifies the type of data being requested as a VIDEO_DEVICE_DATA_TYPE value, typically one of **VpBusData**, **VpControllerData**, or **VpMonitorData.**

The **VpControllerData** and **VpMonitorData** values are relevant only on ARC-compliant platforms. Miniport drivers of x86-type video adapters generally specify **VpBusData**, particularly for adapters on EISA buses. The **VpMachineData** value is reserved for future use.

### `CallbackRoutine`

Pointer to a driver-supplied [HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine) function to be called with the requested information.

### `Context`

Pointer to a caller-determined context parameter to be passed to the *CallbackRoutine*. It typically points to the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) buffer.

## Return value

**VideoPortGetDeviceData** returns NO_ERROR if it successfully called the miniport driver's *HwVidQueryDeviceCallback* function with configuration information.

## Remarks

**VideoPortGetDeviceData** cannot be called from a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) functions, or from [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc), or from a callback to [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution).

The registry tree from which **VideoPortGetDeviceData** retrieves configuration information is *volatile*; that is, it is re-created by the system loader or HAL every time the system is loaded. Because this information is collected and stored early in the boot process, the bus-relative configuration information returned by [VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata) can be more complete.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)