# KS_VideoControlFlags enumeration

## Description

The KS_VideoControlFlags enumeration defines video control capabilities for a specific stream.

## Constants

### `KS_VideoControlFlag_FlipHorizontal`

The minidriver is capable of flipping the image horizontally.

### `KS_VideoControlFlag_FlipVertical`

The minidriver is capable of flipping the image vertically.

### `KS_Obsolete_VideoControlFlag_ExternalTriggerEnable`

This value is obsolete. Do not use.

### `KS_Obsolete_VideoControlFlag_Trigger`

This value is obsolete. Do not use.

### `KS_VideoControlFlag_ExternalTriggerEnable`

The minidriver can enable acquisition of a single video frame based on an external trigger. An external trigger typically is hardware-specific.

### `KS_VideoControlFlag_Trigger`

The minidriver can enable acquisition of a single video frame based on a programmatic trigger.

### `KS_VideoControlFlag_IndependentImagePin`

Determines if the image pin is independent of the video pin.

Supported starting with Windows 8.

### `KS_VideoControlFlag_StillCapturePreviewFrame`

Reserved for system use. Do not use in your driver.

Supported starting with Windows 8.

### `KS_VideoControlFlag_StartPhotoSequenceCapture`

Begin photo sequence capture operation.

Supported starting with Windows 8.1.

### `KS_VideoControlFlag_StopPhotoSequenceCapture`

Stop photo sequence operation.

Supported starting with Windows 8.1.

## See also

[KSPROPERTY_VIDEOCONTROL_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videocontrol_caps_s)

[KSPROPERTY_VIDEOCONTROL_MODE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videocontrol_mode_s)