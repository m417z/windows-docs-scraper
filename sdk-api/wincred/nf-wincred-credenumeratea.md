# CredEnumerateA function

## Description

The **CredEnumerate** function enumerates the credentials from the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `Filter` [in]

Pointer to a **null**-terminated string that contains the filter for the returned credentials. Only credentials with a *TargetName* matching the filter will be returned. The filter specifies a name prefix followed by an asterisk. For instance, the filter "FRED*" will return all credentials with a *TargetName* beginning with the string "FRED".

If **NULL** is specified, all credentials will be returned.

### `Flags` [in]

The value of this parameter can be zero or more of the following values combined with a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CRED_ENUMERATE_ALL_CREDENTIALS**<br><br>0x1 | This function enumerates all of the credentials in the user's credential set. The target name of each credential is returned in the "namespace:attribute=target" format. If this flag is set and the *Filter* parameter is not **NULL**, the function fails and returns **ERROR_INVALID_FLAGS**.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |

### `Count` [out]

Count of the credentials returned in the *Credentials* array.

### `Credential` [out]

Pointer to an array of pointers to credentials.
The returned credential is a single allocated block. Any pointers contained within the buffer are pointers to locations within this single allocated block. The single returned buffer must be freed by calling [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status codes can be returned.

| Return code/value | Description |
| --- | --- |
| **ERROR_NOT_FOUND**<br><br>1168 (0x490) | No credential exists matching the specified *Filter*. |
| **ERROR_NO_SUCH_LOGON_SESSION**<br><br>1312 (0x520) | The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set. |
| **ERROR_INVALID_FLAGS**<br><br>1004 (0x3EC) | A flag that is not valid was specified for the *Flags* parameter, or **CRED_ENUMERATE_ALL_CREDENTIALS** is specified for the *Flags* parameter and the *Filter* parameter is not **NULL**. |

## See also

[CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

## Remarks

> [!NOTE]
> The wincred.h header defines CredEnumerate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).