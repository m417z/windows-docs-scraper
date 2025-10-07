# WINBIO\_BDB\_ANSI\_381\_RECORD structure

The **WINBIO\_BDB\_ANSI\_381\_RECORD** structure contains information about a single fingerprint or palm sample from an end user. A collection of these structures is included in each [**WINBIO\_BDB\_ANSI\_381\_HEADER**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bdb-ansi-381-header) structure.

## Members

**BlockLength**

Contains the number of bytes in this structure plus the number of bytes of sample image data.

**HorizontalLineLength**

Specifies the number of pixels in a horizontal line of the sample.

**VerticalLineLength**

Specifies the number of pixels in a vertical line of the sample.

**Position**

A **WINBIO\_BIOMETRIC\_SUBTYPE** value that specifies the finger or palm used to generate the biometric sample. For more information, see Remarks.

**CountOfViews**

This must be set to one (1);

**ViewNumber**

This must be set to one (1);

**ImageQuality**

Reserved. This must be 254 (0xFE).

**ImpressionType**

Reserved.

**Reserved**

Reserved. Must be set to zero (0).

## Remarks

The *Position* member specifies the area of the hand or palm used to make the biometric sample. The Windows Biometric Framework (WBF) currently supports only fingerprint capture and uses the following constants to represent position information.

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
> Do not attempt to validate the value supplied for the *Position* value. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO\_SUBTYPE\_NO\_INFORMATION** or **WINBIO\_SUBTYPE\_ANY**, then validate where appropriate.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

