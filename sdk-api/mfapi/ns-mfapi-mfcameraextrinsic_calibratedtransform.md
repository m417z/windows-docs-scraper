# MFCameraExtrinsic_CalibratedTransform structure

## Description

A transform describing the location of a camera relative to other cameras or an established external reference.

## Members

### `CalibrationId`

A reference GUID identifying the calibration process for the data, allowing different consumers to identify calibration data from the same process.

### `Position`

The transform position.

### `Orientation`

The transform rotation.

## Remarks

The **Position** value should be expressed in real-world coordinates in units of meters. The coordinate system of both position and orientation should be right-handed Cartesian as shown in the following diagram.

![Right-handed Cartesian coordinate system](https://learn.microsoft.com/windows/win32/api/mfapi/images/MFCameraExtrinsic_Diagram.png)

**Important**

The **Position** and **Orientation** have different interpretations for stand-alone sensor groups, and for Windows Mixed Reality devices.

### Stand-alone sensor groups

For stand-alone sensor groups, the position and orientation express the location of the origin of the group in the sensor's coordinate system. For example, a **Position** value of {-5, 0, 0} means that the origin is 5 meters to the left of the sensor, and therefore the sensor is 5 meters to the right of the origin. A sensor that is positioned 2 meters above the origin should specify a **Position** of {0, -2, 0} because that is the position of the origin relative to the sensor.

If the sensor is aligned with the origin, the rotation is the identity quaternion and the forward vector is along the -Z axis {0, 0, -1}. If the sensor is rotated +30 degrees around the Y axis from the origin (i.e. to the left), then the **Orientation** value should be a rotation of -30 degrees around the Y axis, because it represents the orientation of the origin, relative to the sensor.

### Windows Mixed Reality devices

Sensors attached to a Windows Mixed Reality device (e.g. a HoloLens) express their calibration using the opposite convention, so the position and orientation indicate the location of the *sensor* in the *device's* coordinate system. For example, a sensor which is located 5 centimeters to the right of the origin of the device will have a **Position** of {0.05, 0, 0} because that is the position of the sensor, relative to the device. Likewise, if a sensor is rotated +10 degrees around the Y axis from the device (i.e. to the left), then the **Orientation** value will be a rotation of +10 degrees about the Y axis, because it represents the orientation of the sensor, relative to the device.
In addition, the **CalibrationId** can be passed to [SpatialGraphInteropPreview.CreateLocatorForNode](https://learn.microsoft.com/uwp/api/windows.perception.spatial.preview.spatialgraphinteroppreview.createlocatorfornode) to create a [SpatialLocator](https://learn.microsoft.com/uwp/api/windows.perception.spatial.spatiallocator) which represents the Windows Mixed Reality device. This can be used to compute the location of the sensor in space for a given frame, by querying the location of the **SpatialLocator** at the time the frame was captured, and combining this with the **Position** and **Orientation** of the **MFCameraExtrinsic_CalibratedTransform**. To query the device's location for a frame, pass the timestamp of the frame given by [IMFSample::GetSampleTime](https://learn.microsoft.com/windows/win32/api/mfobjects/nf-mfobjects-imfsample-getsampletime) to [PerceptionTimestampHelper.FromSystemRelativeTargetTime](https://learn.microsoft.com/uwp/api/windows.perception.perceptiontimestamphelper.fromsystemrelativetargettime), and pass the resulting **PerceptionTimestamp** to [SpatialLocator.TryLocateAtTimestamp](https://learn.microsoft.com/uwp/api/windows.perception.spatial.spatiallocator.trylocateattimestamp).

To determine whether an **IMFSample** came from a sensor attached to a Windows Mixed Reality device, look for the following property attached to the frame, set to `MFCameraExtrinsicsCalibrationType_SpatialGraphDynamicNode`:

```cpp
typedef enum _MFCameraExtrinsicsCalibrationType
{
    MFCameraExtrinsicsCalibrationType_Unknown = 0,
    MFCameraExtrinsicsCalibrationType_SpatialGraphDynamicNode = 1
} MFCameraExtrinsicsCalibrationType;

DEFINE_GUID(MFSampleExtension_CameraExtrinsicsCalibrationType, 0x3524e3b0, 0xc355, 0x49f1, 0xb8, 0xb0, 0xd0, 0xdd, 0x62, 0xde, 0x37, 0xa7);
```

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)