# WINBIO\_EVENT structure

The **WINBIO\_EVENT** structure contains status information sent to the callback routine when an event notice is raised.

## Members

**Type**

A value that specifies the type of service provider event notice raised. The only provider currently supported is the fingerprint sensor. This sensor supports the following flags.

**WINBIO\_EVENT\_FP\_UNCLAIMED** (The sensor detected a finger swipe that was not requested by the application or by the window that currently has focus. The Windows Biometric Framework calls into your callback function to indicate that a finger swipe has occurred but does not try to identify the fingerprint.)

**WINBIO\_EVENT\_FP\_UNCLAIMED\_IDENTIFY** (The sensor detected a finger swipe that was not requested by the application or by the window that currently has focus. The Windows Biometric Framework attempts to identify the fingerprint and passes the result of that process to your callback function.)

**Parameters**

**Unclaimed**

Structure returned for biometric sample capture.

**UnitId**

The biometric unit that generated the sample.

**RejectDetail**

A **ULONG** value that contains additional information regarding failure to capture a biometric sample. If a capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

- WINBIO\_FP\_TOO\_HIGH
- WINBIO\_FP\_TOO\_LOW
- WINBIO\_FP\_TOO\_LEFT
- WINBIO\_FP\_TOO\_RIGHT
- WINBIO\_FP\_TOO\_FAST
- WINBIO\_FP\_TOO\_SLOW
- WINBIO\_FP\_POOR\_QUALITY
- WINBIO\_FP\_TOO\_SKEWED
- WINBIO\_FP\_TOO\_SHORT
- WINBIO\_FP\_MERGE\_FAILURE

**UnclaimedIdentify**

Structure returned for biometric capture and identification. Identification determines whether a sample can be associated with an existing biometric template.

**UnitId**

The biometric unit that generated the sample.

**Identity**

A [**WINBIO\_IDENTITY**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-identity) structure that contains the GUID or SID of the user providing the biometric sample.

**SubFactor**

A [**WINBIO\_BIOMETRIC\_SUBTYPE**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-biometric-subtype-constants) value that specifies the sub-factor associated with a biometric sample. The Windows Biometric Framework (WBF) currently supports only fingerprint capture and uses the following constants to represent sub-type information.

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
> Do not attempt to validate the value supplied for the *SubFactor* value. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO\_SUBTYPE\_NO\_INFORMATION** or **WINBIO\_SUBTYPE\_ANY**, then validate where appropriate.

**RejectDetail**

A **ULONG** value that contains additional information about the failure to capture a biometric sample. If the capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

- WINBIO\_FP\_TOO\_HIGH
- WINBIO\_FP\_TOO\_LOW
- WINBIO\_FP\_TOO\_LEFT
- WINBIO\_FP\_TOO\_RIGHT
- WINBIO\_FP\_TOO\_FAST
- WINBIO\_FP\_TOO\_SLOW
- WINBIO\_FP\_POOR\_QUALITY
- WINBIO\_FP\_TOO\_SKEWED
- WINBIO\_FP\_TOO\_SHORT
- WINBIO\_FP\_MERGE\_FAILURE

**Error**

Structure that identifies the success or failure of the operation being monitored.

**ErrorCode**

**HRESULT** value that contains S\_OK or an error code that resulted from computations performed by the Windows Biometric Framework.

## Remarks

Call the [**WinBioRegisterEventMonitor**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioregistereventmonitor) function to register a callback routine to receive event notifications from the Windows Biometric Framework. The callback is a custom function that you must define for your application.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WinBioRegisterEventMonitor**](https://learn.microsoft.com/windows/desktop/api/Winbio/nf-winbio-winbioregistereventmonitor)

