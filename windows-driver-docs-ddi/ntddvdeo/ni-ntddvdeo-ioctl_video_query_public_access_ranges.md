# IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES IOCTL

## Description

Returns an array, possibly with one element, of address ranges used to program the adapter registers or ports directly. Support for this nonmodal request is optional.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns an array of [VIDEO_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_public_access_ranges) in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver returns an address range or ranges, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_PUBLIC_ACCESS_RANGES); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_public_access_ranges)