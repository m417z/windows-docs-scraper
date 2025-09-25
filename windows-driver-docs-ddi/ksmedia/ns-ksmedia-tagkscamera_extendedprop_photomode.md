# tagKSCAMERA_EXTENDEDPROP_PHOTOMODE structure

## Description

The **KSCAMERA_EXTENDEDPROP_PHOTOMODE** structure contains the property data for the history frame counts in photo mode. This structure is used when setting or retrieving the data for the [KSPROPERTY_CAMERACONTROL_EXTENDED_PHOTOMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-photomode2) extended control property.

## Members

### `RequestedHistoryFrames`

The number of history frames to reserve by the driver. The value of **RequestedHistoryFrames** <= **MaxHistoryFrames**.

### `MaxHistoryFrames`

Maximum number of history frames supported by the driver.

### `SubMode`

Not used. Set to 0.

### `Reserved`

Reserved. Set to 0.

## See also

[KSPROPERTY_CAMERACONTROL_EXTENDED_PHOTOMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-photomode2)