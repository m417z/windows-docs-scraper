## Description

**KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_SETTING** contains the x and y origin and window size of the digital window in Q24 format.

## Members

### `OriginX`

The origin of the digital window along the x-axis in Q24 format. Must default to 0. *OriginX* may not be less than *PorchLeft* nor greater than *PorchRight – WindowSize*.

### `OriginY`

The origin of the digital window along the y-axis in Q24 format. Must default to 0. *OriginY* may not be less than *TopPorch* nor greater than *PorchBottom – WindowSize*.

### `WindowSize`

The size of the digital window along both axis in Q24 format. This is the fraction of the full view visible along both the x and y axis. *WindowSize* must default to 0x01000000 (1.0 in Q24). *WindowSize* may not be less than *MinWindowSize* nor larger than *MaxWindowSize*. In addition, *WindowSize* plus *OriginX* may not be greater than *PorchRight*; *WindowsSize* plus *OriginY* may not be greater than *PorchBottom*.

### `Reserved`

Reserved. Set to 0.

## Remarks

These parameters are read-only if KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_AUTOFACEFRAMING is set in the Flags field. If KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_AUTOFACEFRAMING is set during a SET operation, the following parameters are ignored.

## See also

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_configcapsheader)

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_configcaps)

[KSCAMERA_METADATA_DIGITALWINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_metadata_digitalwindow)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow-configcaps)

[Digital Window overview](https://learn.microsoft.com/windows-hardware/drivers/stream/digital-window-overview)