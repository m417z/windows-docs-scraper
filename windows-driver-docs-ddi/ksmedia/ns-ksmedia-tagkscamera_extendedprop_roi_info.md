# tagKSCAMERA_EXTENDEDPROP_ROI_INFO structure

## Description

This structure contains information about an ROI.

## Members

### `Region`

These are the relative coordinates in Q31 format on the frame that face detection is running.

### `Flags`

These are VIDEOPROCFLAG flags that indicate the op mode for the ISP control. For focus ROI, the default value is 0 representing focus region configuration without initiating a focus.

### `Weight`

This is the weight of the region (0-100).

### `RegionOfInterestType`

If the region is a face, this value is KSCAMERA_EXTENDEDPROP_ROITYPE_FACE. If the region is anything other than face, this value is KSCAMERA_EXTENDEDPROP_ROITYPE_UNKNOWN. For more information, see the [KSCAMERA_EXTENDEDPROP_ROITYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-kscamera_extendedprop_roitype) enumeration.