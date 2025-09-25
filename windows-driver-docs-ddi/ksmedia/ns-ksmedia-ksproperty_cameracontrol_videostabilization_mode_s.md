# KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_S structure

## Description

Describes video stabilization control properties in the **PROPSETID_VIDCAP_CAMERACONTROL_VIDEO_STABILIZATION** camera control property set. This structure specifies property values that are used in requests to the camera driver.

## Members

### `VideoStabilizationMode`

Indicates the selected video stabilization modes. This member has one of these possible values:

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_OFF

The video stabilization mode should not activate.

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_AUTO

The device automatically controls video stabilization. This value is valid only if **KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_FLAGS_AUTO** is set in the **Capabilities** member.

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_LOW

Video stabilization is set at a low level.

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_MEDIUM

Video stabilization is set at a medium level.

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_HIGH

Video stabilization is set at a high level.

### `Capabilities`

Indicates whether the device and driver support setting video stabilization control automatically or manually. This member a bitwise **OR** of these possible values:

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_FLAGS_AUTO

The device and driver can automatically control video stabilization.

#### KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_FLAGS_MANUAL

The user can manually set video stabilization modes.

## Remarks

The video stabilization settings specified with this structure affect only the device and have no effect on applications' software video stabilization.

## See also

[KSPROPERTY_CAMERACONTROL_VIDEO_STABILIZATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_cameracontrol_video_stabilization_mode)

[KSPROPERTY_CAMERACONTROL_VIDEO_STABILIZATION_MODE_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-video-stabilization-mode-property)