## Description

**LookupAccountSidLocalA** is defined as a macro that calls [LookupAccountSidA](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountsida) with `NULL` as the first parameter. Retrieves the name of the account for the specified SID on the local machine.

## Parameters

### `Sid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) to look up.

### `Name` [out, optional]

A pointer to a buffer that receives a **null**-terminated string that contains the account name that corresponds to the *lpSid* parameter.

### `cchName` [in, out]

On input, specifies the size, in **TCHAR**s, of the *lpName* buffer. If the function fails because the buffer is too small or if *cchName* is zero, *cchName* receives the required buffer size, including the terminating **null** character.

### `ReferencedDomainName` [out, optional]

A pointer to a buffer that receives a **null**-terminated string that contains the name of the domain where the account name was found.

On a server, the domain name returned for most accounts in the security database of the local computer is the name of the domain for which the server is a domain controller.

On a workstation, the domain name returned for most accounts in the security database of the local computer is the name of the computer as of the last start of the system (backslashes are excluded). If the name of the computer changes, the old name continues to be returned as the domain name until the system is restarted.

Some accounts are predefined by the system. The domain name returned for these accounts is BUILTIN.

### `cchReferencedDomainName` [in, out]

On input, specifies the size, in **TCHAR**s, of the *lpReferencedDomainName* buffer. If the function fails because the buffer is too small or if *cchReferencedDomainName* is zero, *cchReferencedDomainName* receives the required buffer size, including the terminating **null** character.

### `peUse` [out]

A pointer to a variable that receives a
[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) value that indicates the type of the account.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is similar to [LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida), but restricts the search to the local machine.

> [!NOTE]
> The winbase.h header defines LookupAccountSidLocal as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EqualPrefixSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use)