# tagKSCAMERA_EXTENDEDPROP_ROI_ISPCONTROL structure

## Description

This structure contains information for an ROI ISP control.

## Members

### `ControlId`

The ISP control ID. The following are valid values for this field. These values are defined in ksmedia.h.

* KSPROPERTY_CAMERACONTROL_EXTENDED_WHITEBALANCEMODE
* KSPROPERTY_CAMERACONTROL_EXTENDED_EXPOSUREMODE
* KSPROPERTY_CAMERACONTROL_EXTENDED_FOCUSMODE

### `ROICount`

The number of ROIs associated with this ISP control.

### `Result`

The error results of the last SET operation for this ISP control.

### `Reserved`

Reserved for future use.