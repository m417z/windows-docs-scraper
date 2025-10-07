# GetUserNameW function

## Description

Retrieves the name of the user associated with the current thread.

Use the
[GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa) function to retrieve the user name in a specified format. Additional information is provided by the
[IADsADSystemInfo](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsadsysteminfo) interface.

## Parameters

### `lpBuffer` [out]

A pointer to the buffer to receive the user's logon name. If this buffer is not large enough to contain the entire user name, the function fails. A buffer size of (UNLEN + 1) characters will hold the maximum length user name including the terminating null character. UNLEN is defined in Lmcons.h.

### `pcbBuffer` [in, out]

On input, this variable specifies the size of the *lpBuffer* buffer, in **TCHARs**. On output, the variable receives the number of **TCHARs** copied to the buffer, including the terminating null character.

If *lpBuffer* is too small, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER. This parameter receives the required buffer size, including the terminating null character.

## Return value

If the function succeeds, the return value is a nonzero value, and the variable pointed to by *lpnSize* contains the number of **TCHARs** copied to the buffer specified by *lpBuffer*, including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the current thread is impersonating another client, the
**GetUserName** function returns the user name of the client that the thread is impersonating.

If **GetUserName** is called from a process that is running under the "NETWORK SERVICE" account, the string returned in *lpBuffer* may be different depending on the version of Windows. On Windows XP, the "NETWORK SERVICE" string is returned. On Windows Vista, the “\<HOSTNAME>$” string is returned.

#### Examples

For an example, see
[Getting System Information](https://learn.microsoft.com/windows/desktop/SysInfo/getting-system-information).

> [!NOTE]
> The winbase.h header defines GetUserName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)