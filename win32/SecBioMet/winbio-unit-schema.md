# WINBIO\_UNIT\_SCHEMA structure

The **WINBIO\_UNIT\_SCHEMA** structure describes the capabilities of a biometric unit. It is used by the [**WinBioEnumBiometricUnits**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumbiometricunits) function.

## Members

**UnitId**

A value that identifies the biometric unit.

**PoolType**

A **ULONG** value that specifies the type of the biometric unit. This can be one of the following values:

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| **WINBIO\_POOL\_UNKNOWN** | The type is unknown.<br> |
| **WINBIO\_POOL\_SYSTEM** | The session connects to a shared collection of biometric units managed by the service provider.<br> |
| **WINBIO\_POOL\_PRIVATE** | The session connects to a collection of biometric units that are managed by the caller.<br> |

**BiometricFactor**

A value that specifies the type of the biometric unit. Only **WINBIO\_TYPE\_FINGERPRINT** is currently supported.

**SensorSubType**

A sensor subtype defined for the biometric type specified by the **BiometricFactor** member. Only fingerprint types (**WINBIO\_TYPE\_FINGERPRINT**) are currently supported. The following subtypes are currently defined for fingerprints:

- WINBIO\_SENSOR\_SUBTYPE\_UNKNOWN
- WINBIO\_FP\_SENSOR\_SUBTYPE\_SWIPE
- WINBIO\_FP\_SENSOR\_SUBTYPE\_TOUCH

**Capabilities**

A bitmask of the biometric sensor capabilities. This can be a bitwise **OR** of the following values:

- WINBIO\_CAPABILITY\_SENSOR
- WINBIO\_CAPABILITY\_MATCHING
- WINBIO\_CAPABILITY\_DATABASE
- WINBIO\_CAPABILITY\_PROCESSING
- WINBIO\_CAPABILITY\_ENCRYPTION
- WINBIO\_CAPABILITY\_NAVIGATION
- WINBIO\_CAPABILITY\_INDICATOR
- WINBIO\_CAPABILITY\_VIRTUAL\_SENSOR
> [!Note]
> The **WINBIO\_CAPABILITY\_VIRTUAL\_SENSOR** constant applies only for Windows 10 and later.

**DeviceInstanceId**

A string value that contains the device ID. The string can contain up to 256 Unicode characters including a terminating **NULL** character.

**Description**

A string value that contains a description of the biometric unit. The string can contain up to 256 Unicode characters including a terminating **NULL** character.

**Manufacturer**

A string value that contains the name of the manufacturer. The string can contain up to 256 Unicode characters including a terminating **NULL** character.

**Model**

A string value that contains the model number of the biometric unit. The string can contain up to 256 Unicode characters including a terminating **NULL** character.

**SerialNumber**

A **NULL**-terminated Unicode string that contains the serial number of the biometric unit. The string can contain up to 256 Unicode characters including a terminating **NULL** character.

**FirmwareVersion**

A [**WINBIO\_VERSION**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-version) structure that contains the major and minor version numbers for the biometric unit.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WinBioEnumBiometricUnits**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioenumbiometricunits)

