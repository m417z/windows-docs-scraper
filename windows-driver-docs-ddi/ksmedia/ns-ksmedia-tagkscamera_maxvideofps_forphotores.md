# tagKSCAMERA_MAXVIDEOFPS_FORPHOTORES structure

## Description

The **KSCAMERA_MAXVIDEOFPS_FORPHOTORES** structure contains the property data for maximum frame rate at a particular resolution for a camera supporting preview and capture. This structure is used when setting or retrieving the data for the **KSPROPERTY_CAMERACONTROL_EXTENDED_MAXVIDFPS_PHOTORES** extended control property.

## Members

### `PhotoResWidth`

The photo resolution width in pixels.

### `PhotoResHeight`

The photo resolution height in pixels.

### `PreviewFPSNum`

The numerator value of the preview frame rate.

### `PreviewFPSDenom`

The denominator value of the preview frame rate.

### `CaptureFPSNum`

The numerator value of the capture frame rate.

### `CaptureFPSDenom`

The denominator value of the capture frame rate.

## Remarks

When setting the property, using a KSPROPERTY_TYPE_SET request, the **PhotoResWidth** and **PhotoResHeight** members are supplied by the application based on the available photo media types. The camera driver must retain this resolution information internally. The preview and capture frame rate members must be ignored by the driver on KSPROPERTY_TYPE_SET requests.

For any subsequent KSPROPERTY_TYPE_GET request, the camera driver, based on the resolution provided in the earlier KSPROPERTY_TYPE_SET request, must provide the frame rates for the preview and capture streams. Also, the camera driver must set the **PhotoResWidth** and **PhotoResHeight** to the resolution that was provided with the KSPROPERTY_TYPE_SET request.

If no KSPROPERTY_TYPE_SET request was made for the session, the camera driver set all the members of the **KSCAMERA_MAXVIDEOFPS_FORPHOTORES** structure to 0.

If preview or capture are not supported, such as the case when the camera is a dual pinned camera with only one video pin, it should use the **CaptureFPSNum** and **CaptureFPSDenom** members and set the **PreviewFPSNum** and **PreviewFPSDenom** members to 0.

If **KSCAMERA_EXTENDEDPROP_PHOTOMODE_SEQUENCE** is supported on the *Photo Mode Control* by the camera driver, this control is mandatory.