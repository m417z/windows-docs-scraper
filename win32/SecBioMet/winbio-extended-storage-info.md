# WINBIO\_EXTENDED\_STORAGE\_INFO structure

Contains information about the capabilities and enrollment requirements of the storage adapter for a biometric unit.

## Members

**GenericStorageCapabilities**

The generic capabilities of the storage component that is connected to a specific biometric unit.

**Factor**

The type of biometric unit for which this structure contains information about capabilities and enrollment requirements of the storage adapter. For example, if the value of the **Factor** member is **WINBIO\_TYPE\_FINGERPRINT**, the **WINBIO\_EXTENDED\_STORAGE\_INFO** structure applies to a fingerprint reader and contains the relevant information in the **Specifc.Fingerprint** structure.

**Specific**

Information about the capabilities and enrollment requirements of the storage adapter for a biometric unit related to a specific biometric factor.

**Null**

Reserved. Must be zero.

**FacialFeatures**

Information about the capabilities and enrollment requirements of the storage adapter for a biometric unit related to facial features.

**Capabilities**

The facial recognition capabilities of the storage component that is connected to a specific biometric unit.

**Fingerprint**

Information about the capabilities and enrollment requirements of the storage adapter for a biometric unit related to fingerprint patterns.

**Capabilities**

The fingerprint recognition capabilities of the storage component that is connected to a specific biometric unit

**Iris**

Information about the capabilities and enrollment requirements of the storage adapter for a biometric unit related to iris patterns.

**Capabilities**

The iris recognition capabilities of the storage component that is connected to a specific biometric unit

**Voice**

Information about the capabilities and enrollment requirements of the storage adapter for a biometric unit related to voice patterns.

**Capabilities**

The voice recognition capabilities of the storage component that is connected to a specific biometric unit

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

## See also

[**WINBIO\_BIOMETRIC\_TYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-type-constants)

[**WINBIO\_CAPABILITY Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-capability-constants)

