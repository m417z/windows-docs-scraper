# WINBIO\_BIR\_HEADER structure

The **WINBIO\_BIR\_HEADER** structure contains the header of a biometric information record (BIR).

## Members

**ValidFields**

Bitmask that specifies which fields in this structure are valid. For more information, see [**WINBIO\_BIR\_FIELD Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-field-constants).

**HeaderVersion**

A **WINBIO\_BIR\_VERSION** constant that specifies the header version. Version numbers are 8-bit values where the upper four bits specify the major number and the low four bits specify the minor version number. Currently this must be WINBIO\_CBEFF\_HEADER\_VERSION (0x11).

**PatronHeaderVersion**

A **WINBIO\_BIR\_VERSION** constant that specifies the header version. Version numbers are 8-bit values where the upper four bits specify the major number and the low four bits specify the minor version number. Currently this must be WINBIO\_PATRON\_HEADER\_VERSION (0x11).

**DataFlags**

A value that specifies the format of the header data. This can be a bitwise **OR** of the following security and processing level flags. For more information, see [**WINBIO\_BIR\_DATA\_FLAGS Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data-flags-constants).

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **WINBIO\_DATA\_FLAG\_PRIVACY**<br>((UCHAR)0x02) | The data is encrypted.<br> |
| **WINBIO\_DATA\_FLAG\_INTEGRITY**<br>((UCHAR)0x01) | The data is digitally signed or protected by a message authentication code (MAC).<br> |
| **WINBIO\_DATA\_FLAG\_SIGNED**<br>((UCHAR)0x04) | If this flag and the **WINBIO\_DATA\_FLAG\_INTEGRITY** flag are set, the data is signed. If this flag is not set but the **WINBIO\_DATA\_FLAG\_INTEGRITY** flag is set, a MAC is computed over the data.<br> |
| **WINBIO\_DATA\_FLAG\_RAW**<br>((UCHAR)0x20) | The data is in the format with which it was captured.<br> |
| **WINBIO\_DATA\_FLAG\_INTERMEDIATE**<br>((UCHAR)0x40) | The data is not raw but has not been completely processed.<br> |
| **WINBIO\_DATA\_FLAG\_PROCESSED**<br>((UCHAR)0x80) | The data has been processed.<br> |
| **WINBIO\_DATA\_FLAG\_OPTION\_MASK\_PRESENT**<br>((UCHAR)0x08) | This value is always 1.<br> |

**Type**

A WINBIO\_BIOMETRIC\_TYPE value that specifies the type of biometric data referenced in the biometric information record. Currently only **WINBIO\_TYPE\_FINGERPRINT** is supported. For more information, see [**WINBIO\_BIOMETRIC\_TYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-type-constants).

**Subtype**

A **WINBIO\_BIOMETRIC\_SUBTYPE** value that specifies the sub-factor associated with the biometric data. For more information, see Remarks and [**WINBIO\_BIOMETRIC\_SUBTYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-subtype-constants).

**Purpose**

A **WINBIO\_BIR\_PURPOSE** mask that specifies the intended use of the data. This can be a bitwise **OR** of the following values. For more information, see [**WINBIO\_BIR\_PURPOSE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-purpose-constants).

- WINBIO\_PURPOSE\_VERIFY
- WINBIO\_PURPOSE\_IDENTIFY
- WINBIO\_PURPOSE\_ENROLL
- WINBIO\_PURPOSE\_ENROLL\_FOR\_VERIFICATION
- WINBIO\_PURPOSE\_ENROLL\_FOR\_IDENTIFICATION
- WINBIO\_PURPOSE\_AUDIT

**DataQuality**

A value that specifies the relative quality of the biometric data in the biometric information record (BIR). This can be an integer from 0 to 100 or one of the following values. For more information, see [**WINBIO\_BIR\_QUALITY Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-quality-constants).

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **WINBIO\_DATA\_QUALITY\_NOT\_SET**<br>((WINBIO\_BIR\_QUALITY)-1) | Quality measurements are supported by the BIR creator but no value is set in the BIR.<br> |
| **WINBIO\_DATA\_QUALITY\_NOT\_SUPPORTED**<br>((WINBIO\_BIR\_QUALITY)-2) | Quality measurements are not supported by the BIR creator.<br> |

**CreationDate**

The date and time, in Coordinated Universal Time (Greenwich Mean Time), that the BIR was created.

**ValidityPeriod**

The period for which the BIR is valid.

**BeginDate**

The date and time, in Coordinated Universal Time, that the validity period starts.

**EndDate**

The date and time, in Coordinated Universal Time, at which the BIR ceases to be valid.

**BiometricDataFormat**

A [**WINBIO\_REGISTERED\_FORMAT**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-registered-format) structure that specifies the data format of the standard data block in the [**WINBIO\_BIR**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir) structure. The **WINBIO\_REGISTERED\_FORMAT** members cannot be zero. You can use the following constants to simplify error checking.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| **WINBIO\_NO\_FORMAT\_OWNER\_AVAILABLE**<br>((USHORT)0) | No IBIA (International Biometric Industry Association) assigned owner value has been specified.<br> |
| **WINBIO\_NO\_FORMAT\_TYPE\_AVAILABLE**<br>((USHORT)0) | No format type has been specified.<br> |

**ProductId**

A [**WINBIO\_REGISTERED\_FORMAT**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-registered-format) structure that specifies the product ID of the component that generated the standard data block in the BIR. The **WINBIO\_REGISTERED\_FORMAT** members can be zero.

## Remarks

The *Subtype* parameter specifies the sub-factor associated with the biometric data. Currently, the Windows Biometric Framework (WBF) supports only fingerprint capture and uses the following constants to represent sub-type information:

- WINBIO\_ANSI\_381\_POS\_UNKNOWN
- WINBIO\_ANSI\_381\_POS\_RH\_THUMB
- WINBIO\_ANSI\_381\_POS\_RH\_INDEX\_FINGER
- WINBIO\_ANSI\_381\_POS\_RH\_MIDDLE\_FINGER
- WINBIO\_ANSI\_381\_POS\_RH\_RING\_FINGER
- WINBIO\_ANSI\_381\_POS\_RH\_LITTLE\_FINGER
- WINBIO\_ANSI\_381\_POS\_LH\_THUMB
- WINBIO\_ANSI\_381\_POS\_LH\_INDEX\_FINGER
- WINBIO\_ANSI\_381\_POS\_LH\_MIDDLE\_FINGER
- WINBIO\_ANSI\_381\_POS\_LH\_RING\_FINGER
- WINBIO\_ANSI\_381\_POS\_LH\_LITTLE\_FINGER
- WINBIO\_ANSI\_381\_POS\_RH\_FOUR\_FINGERS
- WINBIO\_ANSI\_381\_POS\_LH\_FOUR\_FINGERS
- WINBIO\_ANSI\_381\_POS\_TWO\_THUMBS

> [!IMPORTANT]
>
> Do not attempt to validate the value supplied for the *Subtype* parameter value. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO\_SUBTYPE\_NO\_INFORMATION** or **WINBIO\_SUBTYPE\_ANY**, then validate where appropriate.

If any of the following bits are asserted, the **WINBIO\_BIR\_HEADER** structure is not correctly formed.

```C++
#define WINBIO_BIR_FIELD_NEVER_VALID    (WINBIO_BIR_FIELD_SUBHEAD_COUNT |   \
                                         WINBIO_BIR_FIELD_PATRON_ID |       \
                                         WINBIO_BIR_FIELD_INDEX |           \
                                         WINBIO_BIR_FIELD_CHALLENGE |       \
                                         WINBIO_BIR_FIELD_PAYLOAD )
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WINBIO\_BIOMETRIC\_SUBTYPE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-subtype-constants)

[**WINBIO\_BIR**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir)

[**WINBIO\_BIR\_DATA\_FLAGS Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-data-flags-constants)

[**WINBIO\_BIR\_FIELD Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-field-constants)

[**WINBIO\_BIR\_PURPOSE Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-purpose-constants)

[**WINBIO\_BIR\_QUALITY Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-quality-constants)

[**WINBIO\_BIR\_VERSION Constants**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-version-constants)

