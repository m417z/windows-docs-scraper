# WINBIO\_EXTENDED\_ENROLLMENT\_PARAMETERS structure

The **WINBIO\_EXTENDED\_ENROLLMENT\_PARAMETERS** structure contains additional information that an engine adapter needs to create an enrollment template.

## Members

**Size**

The size (in bytes) of the **WINBIO\_EXTENDED\_ENROLLMENT\_PARAMETERS** structure.

**SubFactor**

One of the [**WINBIO\_BIOMETRIC\_SUBTYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-subtype-constants) values that provides additional information about the enrollment.

## Remarks

The Windows Biometric Framework passes this structure to the [**EngineAdapterSetEnrollmentParameters**](https://learn.microsoft.com/windows/desktop/api/Winbio_adapter/nc-winbio_adapter-pibio_engine_set_enrollment_parameters_fn) method during an enrollment operation.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_adapter.h (include Winbio\_adapter.h) |

