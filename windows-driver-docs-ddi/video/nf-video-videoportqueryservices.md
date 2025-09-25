# VideoPortQueryServices function

## Description

The **VideoPortQueryServices** function exposes a specified interface that is implemented by the video port driver.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `ServicesType` [in]

A value from the [VIDEO_PORT_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ne-video-video_port_services) enumerated type that specifies which interface is being requested.

### `Interface` [in, out]

Pointer to an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure, which contains basic information about the requested interface. See the following **Remarks** section for more information.

## Return value

If **VideoPortQueryServices** succeeds, it returns NO_ERROR; otherwise, it returns an error code.

## Remarks

If the *ServicesType* parameter is set to **VideoPortServicesI2C**, the *Interface* parameter must be a pointer to a [VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface) structure, cast as a pointer to an INTERFACE structure.

Similarly, if the *ServicesType* parameter is set to **VideoPortServicesAGP**, the *Interface* parameter must be a pointer to either a [VIDEO_PORT_AGP_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface) structure, or a [VIDEO_PORT_AGP_INTERFACE_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface_2) structure, each cast as a pointer to an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

The VIDEO_PORT_AGP_INTERFACE and VIDEO_PORT_AGP_INTERFACE_2 structures are nearly identical, except that the latter structure has a member that points to the [AgpSetRate](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_set_rate) function, which is used to reset the transfer rate for an AGP chipset. A video miniport driver querying AGP support should call **VideoPortQueryServices** first with *Interface* pointing to a VIDEO_PORT_AGP_INTERFACE_2 structure. If that call fails, the miniport driver can then make another call to **VideoPortQueryServices**, this time with *Interface* pointing to a VIDEO_PORT_AGP_INTERFACE structure.

If the *ServicesType* parameter is set to **VideoPortServicesInt10**, the *Interface* parameter must be a pointer to a [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure, cast as a pointer to an INTERFACE structure.

If the *ServicesType* parameter is set to **VideoPortServicesDebugReport**, the *Interface* parameter must be a pointer to a [VIDEO_PORT_DEBUG_REPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_debug_report_interface) structure, cast as a pointer to an INTERFACE structure.

If the *ServicesType* parameter is set to **VideoPortServicesWCMemoryProtection**, the *Interface* parameter must be a pointer to a [VIDEO_PORT_WCMEMORYPROTECTION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_wcmemoryprotection_interface) structure, cast as a pointer to an INTERFACE structure.

## See also

[AgpSetRate](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_set_rate)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[VIDEO_PORT_AGP_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface)

[VIDEO_PORT_AGP_INTERFACE_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface_2)

[VIDEO_PORT_DEBUG_REPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_debug_report_interface)

[VIDEO_PORT_I2C_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_i2c_interface)

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)

[VIDEO_PORT_WCMEMORYPROTECTION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_wcmemoryprotection_interface)