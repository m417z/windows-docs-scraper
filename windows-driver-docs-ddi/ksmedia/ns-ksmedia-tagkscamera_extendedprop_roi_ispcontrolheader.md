# tagKSCAMERA_EXTENDEDPROP_ROI_ISPCONTROLHEADER structure

## Description

This structure contains the header information for ROI ISP controls.

## Members

### `Size`

The sum of this structure size, all [KSCAMERA_EXTENDEDPROP_ROI_ISPCONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_extendedprop_roi_ispcontrol) structures, and all KSCAMERA_EXTENDEDPROP_ROI_RECTINFO structures that follow

### `ControlCount`

The number of ISP controls. If this value is 0, the ROI control will remove all ROIs previously configured. This effectively clears up all ROIs configured and resets the driver to the default ROI.

### `Reserved`

Reserved for future use.