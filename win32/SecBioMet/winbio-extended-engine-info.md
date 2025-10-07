# WINBIO\_EXTENDED\_ENGINE\_INFO structure

Contains information about the capabilities and enrollment requirements of the engine adapter for a biometric unit.

## Members

**GenericEngineCapabilities**

The generic capabilities of the engine component that is connected to a specific biometric unit.

**Factor**

The type of biometric unit for which this structure contains information about capabilities and enrollment requirements of the engine adapter. For example, if the value of the **Factor** member is **WINBIO\_TYPE\_FINGERPRINT**, the **WINBIO\_EXTENDED\_ENGINE\_INFO** structure applies to a fingerprint reader and contains the relevant information in the **Specifc.Fingerprint** structure.

**Specific**

Information about the capabilities and enrollment requirements of the engine adapter for a biometric unit related to a specific biometric factor.

**Null**

Reserved. Must be zero.

**FacialFeatures**

Information about the capabilities and enrollment requirements of the engine adapter for a biometric unit related to facial features.

**Capabilities**

Reserved. Must be zero.

**EnrollmentRequirements**

**Null**

Reserved. Must be zero.

**Fingerprint**

Information about the capabilities and enrollment requirements of the engine adapter for a biometric unit related to fingerprint patterns.

**Capabilities**

Reserved. Must be zero.

**EnrollmentRequirements**

The number of good samples required to create a new fingerprint template.

**GeneralSamples**

The total number of good samples required to create a new fingerprint template.

**Center**

The number of good samples for the center of the fingerprint required to create a new fingerprint template.

**TopEdge**

The number of good samples for the top edge of the fingerprint required to create a new fingerprint template.

**BottomEdge**

The number of good samples for the bottom edge of the fingerprint required to create a new fingerprint template.

**LeftEdge**

The number of good samples for the left edge of the fingerprint required to create a new fingerprint template.

**RightEdge**

The number of good samples for the right edge of the fingerprint required to create a new fingerprint template.

**Iris**

Information about the capabilities and enrollment requirements of the engine adapter for a biometric unit related to iris patterns.

**Capabilities**

Reserved. Must be zero.

**EnrollmentRequirements**

**Null**

Reserved. Must be zero.

**Voice**

Information about the capabilities and enrollment requirements of the engine adapter for a biometric unit related to voice patterns.

**Capabilities**

Reserved. Must be zero.

**EnrollmentRequirements**

**Null**

Reserved. Must be zero.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

## See also

[**WINBIO\_CAPABILITY Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-capability-constants)

[**WINBIO\_BIOMETRIC\_TYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-type-constants)

