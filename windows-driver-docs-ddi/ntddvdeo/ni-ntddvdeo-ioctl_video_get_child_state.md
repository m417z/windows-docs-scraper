# IOCTL_VIDEO_GET_CHILD_STATE IOCTL

## Description

Determines whether a child device is currently enabled. Although miniport driver support for this modal request is optional, it is highly recommended. Otherwise, Windows 2000 and later must call the BIOS to perform the operation, which is very inefficient and can adversely affect system robustness. If the BIOS cannot handle this request, then Windows 2000 or later considers the child device to be active.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a pointer to a ULONG, containing the index of the child device, as specified in [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor).

### Input buffer length

### Output buffer

The video miniport driver returns a ULONG in the VRP **OutputBuffer** that can be a combination of the following flags:

| **Value** | **Meaning** |
|:--|:--|
| VIDEO_CHILD_ACTIVE | The child device is active. |
| VIDEO_CHILD_DETACHED | The child device is detached from the view. This flag is used in DualView implementations to indicate the logical relationships of child devices. See [Supporting DualView (Windows 2000 Model)](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-dualview--windows-2000-model-) for more information. |
| VIDEO_CHILD_NOPRUNE_FREQ | The child device can drive an image at any refresh rate, regardless of its EDID setting.<br>This flag is used for mode pruning. By default, Windows 2000 and later perform mode pruning for each active child. When the miniport driver wants to prevent the operating system from performing mode pruning on specific child devices, however, it should use this flag. |
| VIDEO_CHILD_NOPRUNE_SIZE | The child device can drive an image of any size, regardless of its EDID setting.<br>This flag is used for mode pruning. By default, Windows 2000 and later perform mode pruning for each active child. When the miniport driver wants to prevent the operating system from performing mode pruning on specific child devices, however, it should use this flag. |

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The video miniport driver sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(ULONG).

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)