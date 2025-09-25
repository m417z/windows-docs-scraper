# VideoPortGetAgpServices function

## Description

The **VideoPortGetAgpServices** function is **obsolete** and is supported only for backward compatibility with existing drivers. In its place, driver writers should use [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices).

**VideoPortGetAgpServices** returns a list of video port driver-implemented AGP service functions.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `AgpServices` [in]

Pointer to an uninitialized, miniport driver-allocated [VIDEO_PORT_AGP_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/ns-videoagp-_video_port_agp_services) structure.

## Return value

**VideoPortGetAgpServices** returns **TRUE** after it successfully initializes the VIDEO_PORT_AGP_SERVICES structure to which *AgpServices* points; otherwise it returns **FALSE**.

## Remarks

PnP video miniport drivers that can use AGP should call **VideoPortGetAgpServices**.

The video port driver initializes the [VIDEO_PORT_AGP_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/ns-videoagp-_video_port_agp_services) structure as follows:

* All function pointers are initialized to point to the corresponding video port driver-implemented AGP service functions.
* The **AllocationLimit** field is initialized to the maximum amount of AGP memory that a miniport driver is allowed to commit, in bytes.

## See also

[AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical)

[AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual)

[AgpFreePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_physical)

[AgpFreeVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_virtual)

**AgpReleasePhysical**

[AgpReleaseVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_virtual)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)

[VIDEO_PORT_AGP_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/ns-videoagp-_video_port_agp_services)

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)