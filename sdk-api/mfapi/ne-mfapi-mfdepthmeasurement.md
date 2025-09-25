## Description

Specifies the measurement system for a depth value in a video frame.

## Constants

### `DistanceToFocalPlane:0`

The measurement is the distance to the focal plane.

### `DistanceToOpticalCenter:1`

The measurement is the distance to the optical center.

## Remarks

Use a value from this enumeration with the [MF_MT_DEPTH_MEASUREMENT](https://learn.microsoft.com/windows/win32/medfound/mf-mt-depth-measurement) attribute.

The distance to focal plane is typically easier to consume in a 3D Euclidian coordinate system.

![Illustration of DistanceToFocalPlane](https://learn.microsoft.com/windows/win32/api/mfapi/images/distance_to_focal_plane.png)

The distance to focal center format is typically raw data from sensor such as time of flight cameras.

![Illustration of DistanceToOpticalCenter](https://learn.microsoft.com/windows/win32/api/mfapi/images/distance_to_optical_center.png)

## See also