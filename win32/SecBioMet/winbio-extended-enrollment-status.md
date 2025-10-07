# WINBIO\_EXTENDED\_ENROLLMENT\_STATUS structure

Contains additional information about the status of an enrollment that is in progress.

## Members

**TemplateStatus**

The status of sample collection for the enrollment template. The following values are possible for this member.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **S\_OK** | The enrollment is ready to be saved.<br> |
| **WINBIO\_E\_INVALID\_OPERATION** | No enrollment is in progress.<br> |
| **WINBIO\_I\_MORE\_DATA** | More samples are required to complete the template.<br> |
| **WINBIO\_E\_BAD\_CAPTURE** | The most recent sample is not usable.<br> |

**RejectDetail**

The reason that the most recent sample is unusable, if the value of the **TemplateStatus** member is **WINBIO\_E\_BAD\_CAPTURE**.

**PercentComplete**

The best estimate from the engine adapter for the percentage of the template that is complete, as a value from 0 to 100.

**Factor**

The type of biometric unit for which this structure contains information about capabilities and enrollment requirements of the engine adapter. For example, if the value of the **Factor** member is **WINBIO\_TYPE\_FINGERPRINT**, the [**WINBIO\_EXTENDED\_ENGINE\_INFO**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-extended-engine-info) structure applies to a fingerprint reader and contains the relevant information in the **Specifc.Fingerprint** structure.

**SubFactor**

A **WINBIO\_BIOMETRIC\_SUBTYPE** value that provides additional information about the enrollment.

**Specific**

Information about the status of an enrollment that is in progress for a specific biometric factor.

**Null**

Reserved. Must be zero.

**FacialFeatures**

Information about the status of an enrollment that is in progress for facial features.

**BoundingBox**

The position within the camera frame of the face of the individual to enroll, in pixels. The size of the camera frame determines the upper limit on the number of pixels for this position. Get the **WINBIO\_PROPERTY\_EXTENDED\_SENSOR\_INFO** property to determine the size of the camera frame. A client that uses the presence monitor must perform the scaling operation to map the position to the camera frame.

**Distance**

The distance between the actual location of the face and the ideal focal distance for the face. This value ranges from -100 to 100. 0 indicates the ideal distance, positive values indicate that the actual location of the face is too far away, and negative values indicate that the actual location is too close.

**Fingerprint**

Information about the status of an enrollment that is in progress for fingerprint patterns.

**GeneralSamples**

The total number of samples required to create a new fingerprint template.

**Center**

The number of samples for the center of the fingerprint required to create a new fingerprint template.

**TopEdge**

The number of samples for the top edge of the fingerprint required to create a new fingerprint template.

**BottomEdge**

The number of samples for the bottom edge of the fingerprint required to create a new fingerprint template.

**LeftEdge**

The number of samples for the left edge of the fingerprint required to create a new fingerprint template.

**RightEdge**

The number of samples for the right edge of the fingerprint required to create a new fingerprint template.

**Iris**

Information about the status of an enrollment that is in progress for iris patterns.

**EyeBoundingBox\_1**

The position within the camera frame of one of the irises of the individual to enroll, in pixels. If the iris-recognition system is only monitoring one eye, this position is of the iris of that eye. If the iris-recognition system is monitoring both eyes, but only one eye is in the camera frame, this position is of the iris of the eye in the camera frame. If the iris-recognition system is monitoring both eyes, and both eyes are in the camera frame, this position is probably of the iris of the right eye of the individual.

The size of the camera frame determines the upper limit on the number of pixels for this position. Get the **WINBIO\_PROPERTY\_EXTENDED\_SENSOR\_INFO** property to determine the size of the camera frame. A client that uses the presence monitor must perform the scaling operation to map the position to the camera frame.

**EyeBoundingBox\_2**

The position within the camera frame of one of the irises of the individual to enroll, in pixels. If the iris-recognition system is only monitoring one eye, or if only one eye is in the camera frame, this value is empty. If the iris-recognition system is monitoring both eyes, and both eyes are in the camera frame, this position is probably of iris of the left eye of the individual.

The size of the camera frame determines the upper limit on the number of pixels for this position. Get the **WINBIO\_PROPERTY\_EXTENDED\_SENSOR\_INFO** property to determine the size of the camera frame. A client that uses the presence monitor must perform the scaling operation to map the position to the camera frame.

**PupilCenter\_1**

The position of the center of one of the pupils of the individual to enroll. If the iris-recognition system is only monitoring one eye, this position is of the center of the pupil of that eye. If the iris-recognition system is monitoring both eyes, but only one eye is in the camera frame, this position is of the center of the pupil of the eye in the camera frame. If the iris-recognition system is monitoring both eyes, and both eyes are in the camera frame, this position is probably of the center of the pupil of the right eye of the individual.

**PupilCenter\_2**

The position of the center of one of the pupils of the individual to enroll. If the iris-recognition system is only monitoring one eye, or if only one eye is in the camera frame, this value is empty. If the iris-recognition system is monitoring both eyes, and both eyes are in the camera frame, this position is probably of the center of the pupil of the left eye of the individual.

**Distance**

The distance between the actual location of the iris and the ideal focal distance for the iris. This value ranges from -100 to 100. 0 indicates the ideal distance, positive values indicate that the actual location of the iris is too far away, and negative values indicate that the actual location is too close.

**Voice**

Information about the status of an enrollment that is in progress for voice patterns.

**Reserved**

Reserved.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

