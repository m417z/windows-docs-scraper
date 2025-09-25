# _VIDEO_PORT_AGP_SERVICES structure

## Description

The VIDEO_PORT_AGP_SERVICES structure is **obsolete** and is supported only for backward compatibility with existing drivers. In its place, driver writers should use [VIDEO_PORT_AGP_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface).

The VIDEO_PORT_AGP_SERVICES structure describes the AGP service routines provided by the video port driver. PnP video miniport drivers that can use AGP should call [VideoPortGetAgpServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nf-videoagp-videoportgetagpservices) to initialize this structure. The video port driver initializes the entire structure; the miniport driver should never change any members.

## Members

### `AgpReservePhysical`

### `AgpReleasePhysical`

### `AgpCommitPhysical`

### `AgpFreePhysical`

### `AgpReserveVirtual`

### `AgpReleaseVirtual`

### `AgpCommitVirtual`

### `AgpFreeVirtual`

### `AllocationLimit`