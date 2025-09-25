# _VIDEO_PORT_AGP_INTERFACE structure

## Description

The VIDEO_PORT_AGP_INTERFACE structure describes the AGP service routines provided by the video port driver.

## Members

### `Size`

Specifies the size in bytes of this structure.

### `Version`

Specifies the version of the interface to be returned by the video port driver. The current interface version is defined in *video.h* and has the form VIDEO_PORT_AGP_INTERFACE_*N*.

### `Context`

Pointer to a video port driver-defined context for the interface.

### `InterfaceReference`

Pointer to the video port driver-implemented reference routine for this interface.

### `InterfaceDereference`

Pointer to the video port driver-implemented dereference routine for this interface.

### `AgpReservePhysical`

Pointer to the video port driver-implemented [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical) routine.

### `AgpReleasePhysical`

Pointer to the video port driver-implemented [AgpReleasePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_physical) routine.

### `AgpCommitPhysical`

Pointer to the video port driver-implemented [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical) routine.

### `AgpFreePhysical`

Pointer to the video port driver-implemented [AgpFreePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_physical) routine.

### `AgpReserveVirtual`

Pointer to the video port driver-implemented [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual) routine.

### `AgpReleaseVirtual`

Pointer to the video port driver-implemented [AgpReleaseVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_virtual) routine.

### `AgpCommitVirtual`

Pointer to the video port driver-implemented [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual) routine.

### `AgpFreeVirtual`

Pointer to the video port driver-implemented [AgpFreeVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_virtual) routine.

### `AgpAllocationLimit`

Specifies the maximum total number of bytes of AGP memory that a miniport driver can commit.

## Remarks

PnP video miniport drivers that can use AGP must fill in the **Size** and **Version** members, and then call the [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) function, which initializes the remaining members of this structure.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices)