# MFPinholeCameraIntrinsics structure

## Description

Contains zero or 1 pinhole camera intrinsic models that describe how to project a 3D point in physical world onto the 2D image frame of a camera. The conventions assumed by this structure imply a left-handed 3D coordinate system, with +X pointing to the right of the sensor, +Y pointing upwards from the sensor, and +Z pointing forward out of the sensor through the center (principal point) of the image.

## Members

### `IntrinsicModelCount`

The number of camera intrinsic models in the *IntrinsicModels* array.

### `IntrinsicModels`

The array of camera intrinsic models in the intrinsic data.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)