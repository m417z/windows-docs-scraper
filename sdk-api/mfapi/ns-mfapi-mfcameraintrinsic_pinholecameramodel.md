# MFCameraIntrinsic_PinholeCameraModel structure

## Description

Represents a pinhole camera model.

## Members

### `FocalLength`

The focal length of the camera.

### `PrincipalPoint`

The principal point of the camera.

## Remarks

For square pixels, the X and Y fields of the **FocalLength** should be the same. The units of the focal length fields are pixels per meter, so dividing the width and height of the image by the X and Y fields of the focal length, respectively, yields the physical size in meters of the image at a distance of one meter from the sensor.

The **PrincipalPoint** field is expressed in pixels, not in normalized coordinates. The origin [0,0] is the bottom, left corner of the image.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)