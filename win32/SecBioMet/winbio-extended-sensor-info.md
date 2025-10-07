# WINBIO\_EXTENDED\_SENSOR\_INFO structure

Contains information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit.

## Members

**GenericSensorCapabilities**

The generic capabilities of the sensor component that is connected to a specific biometric unit.

**Factor**

The type of biometric unit for which this structure contains information about capabilities and enrollment requirements of the sensor adapter. For example, if the value of the **Factor** member is **WINBIO\_TYPE\_FINGERPRINT**, the **WINBIO\_EXTENDED\_SENSOR\_INFO** structure applies to a fingerprint reader and contains the relevant information in the **Specifc.Fingerprint** structure.

**Specific**

Information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit related to a specific biometric factor.

**Null**

Reserved. Must be zero.

**FacialFeatures**

Information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit related to facial features.

**FrameSize**

The size of the camera frame, indicated as a length and width in pixels by the **right** and **bottom** members of the [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. The point (0, 0) represents the top-left corner of the frame.

**FrameOffset**

The offset of the camera frame for the face from the video camera, in pixels. A value of (0, 0) indicates that the camera frame for the face and the video camera completely overlap.

**MandatoryOrientation**

The preferred orientation for the camera.

**Fingerprint**

Information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit related to fingerprint patterns.

**Reserved**

Reserved.

**Iris**

Information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit related to iris patterns.

**FrameSize**

The size of the camera frame, indicated as a length and width in pixels by the **right** and **bottom** members of the [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. The point (0, 0) represents the top-left corner of the frame.

**FrameOffset**

The offset of the camera frame for the iris from the video camera, in pixels. A value of (0, 0) indicates that the camera frame for the iris and the video camera completely overlap.

**MandatoryOrientation**

The preferred orientation for the camera.

**Voice**

Information about the capabilities and enrollment requirements of the sensor adapter for a biometric unit related to voice patterns.

**Reserved**

Reserved.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

## See also

[**WINBIO\_CAPABILITY Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-capability-constants)

[**WINBIO\_BIOMETRIC\_TYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-type-constants)

[**WINBIO\_ORIENTATION Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-orientation-constants)

