# WINBIO\_PRESENCE\_PROPERTIES union

Contains biometric values that the Windows Biometric Framework used to determine that an individual was present.

## Members

**FacialFeatures**

Values for the location of facial features that the Windows Biometric Framework used to determine that an individual was present.

**BoundingBox**

The position within the camera frame of the face of the individual, in pixels. The size of the camera frame determines the upper limit on the number of pixels for this position. Get the **WINBIO\_PROPERTY\_EXTENDED\_SENSOR\_INFO** property to determine the size of the camera frame. A client that uses the presence monitor must perform the scaling operation to map the position to the camera frame .

**Distance**

The distance between the actual location of the face and the ideal focal distance for the face. This value ranges from -100 to 100. 0 indicates the ideal distance, positive values indicate that the actual location of the face is too far away, and negative values indicate that the actual location is too close.

**Iris**

Values for iris location that the Windows Biometric Framework used to determine that an individual was present.

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

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

