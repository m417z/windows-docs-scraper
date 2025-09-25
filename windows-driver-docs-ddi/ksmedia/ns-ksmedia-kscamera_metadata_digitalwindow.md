## Description

**KSCAMERA_METADATA_DIGITALWINDOW** contains metadata header information along with the digital window x and y origin and size in Q24 format.

## Members

### `Header`

A [KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) structure that contains the metadata header information that is filled by the camera driver.

### `Window`

A [KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_setting) structure that contains the x and y origin and size of the digital window in Q24 format.

## See also

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_configcapsheader)

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_configcaps)

[KSCAMERA_EXTENDEDPROP_DIGITALWINDOW_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_digitalwindow_setting)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow)

[KSPROPERTY_CAMERACONTROL_EXTENDED_DIGITALWINDOW_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-digitalwindow-configcaps)

[Digital Window overview](https://learn.microsoft.com/windows-hardware/drivers/stream/digital-window-overview)