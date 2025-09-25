## Description

**KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPS** defines an available resolution and its supported configuration values.

## Members

### `ResolutionX`

The width of the output format in pixels.

### `ResolutionY`

The height of the output format in pixels.

### `PorchTop`

The upper limit of the camera sensor's overscan region expressed as a fraction of the total field of view along the y-axis. This value must be less than or equal to 0.0 in Q24 format.

### `PorchLeft`

The left-most limit of the camera sensor's overscan region expressed as a fraction of the total field of view along the x-axis. This value must be less than or equal to 0.0 in Q24 format.

### `PorchBottom`

The lower limit of the camera sensor's overscan region expressed as a fraction of the total field of view along the y-axis. This value must be greater than or equal to 1.0 in Q24 format.

### `PorchRight`

The right-most limit of the camera sensor's overscan region expressed as a fraction of the total field of view along the x-axis. This value must be greater than or equal to 1.0 in Q24 format

### `NonUpscalingWindowSize`

The value an application should set as the *WindowSize* so it can acquire an image that returns the full fidelity of the sensor. The value is expressed as a Q24 value, between *MinWindowSize* and *MaxWindowSize*.

### `MinWindowSize`

The smallest *WindowSize* the Digital Window control can support for this resolution. This value may be any number greater than 0.0 but less than or equal to 1.0.

### `MaxWindowSize`

The largest *WindowSize* the Digital Window control can support for this resolution. This value must be 1.0 or greater.

### `Reserved`

Reserved. Set to 0.

## See also

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_configcapsheader)

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_setting)

[KSCAMERA_METADATA_DIGITALWINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_metadata_digitalwindow)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow-configcaps)

[Digital Window overview](https://learn.microsoft.com/windows-hardware/drivers/stream/digital-window-overview)