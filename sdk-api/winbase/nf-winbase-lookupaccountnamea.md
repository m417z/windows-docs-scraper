# LookupAccountNameA function

## Description

The **LookupAccountName** function accepts the name of a system and an account as input. It retrieves a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) for the account and the name of the domain on which the account was found.

The [LsaLookupNames](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames) function can also retrieve computer accounts.

## Parameters

### `lpSystemName` [in, optional]

A pointer to a **null**-terminated character string that specifies the name of the system. This string can be the name of a remote computer. If this string is **NULL**, the account name translation begins on the local system. If the name cannot be resolved on the local system, this function will try to resolve the name using domain controllers trusted by the local system. Generally, specify a value for *lpSystemName* only when the account is in an untrusted domain and the name of a computer in that domain is known.

### `lpAccountName` [in]

A pointer to a **null**-terminated string that specifies the account name.

Use a fully qualified string in the domain_name\user_name format to ensure that **LookupAccountName** finds the account in the desired domain.

### `Sid` [out, optional]

A pointer to a buffer that receives the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that corresponds to the account name pointed to by the *lpAccountName* parameter. If this parameter is **NULL**, *cbSid* must be zero.

### `cbSid` [in, out]

A pointer to a variable. On input, this value specifies the size, in bytes, of the *Sid* buffer. If the function fails because the buffer is too small or if *cbSid* is zero, this variable receives the required buffer size.

### `ReferencedDomainName` [out, optional]

A pointer to a buffer that receives the name of the domain where the account name is found. For computers that are not joined to a domain, this buffer receives the computer name. If this parameter is **NULL**, the function returns the required buffer size.

### `cchReferencedDomainName` [in, out]

A pointer to a variable. On input, this value specifies the size, in **TCHAR**s, of the *ReferencedDomainName* buffer. If the function fails because the buffer is too small, this variable receives the required buffer size, including the terminating **null** character. If the *ReferencedDomainName* parameter is **NULL**, this parameter must be zero.

### `peUse` [out]

A pointer to a
[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumerated type that indicates the type of the account when the function returns.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LookupAccountName** function attempts to find a SID for the specified name by first checking a list of well-known SIDs. If the name does not correspond to a well-known SID, the function checks built-in and administratively defined local accounts. Next, the function checks the primary domain. If the name is not found there, trusted domains are checked.

Use fully qualified account names (for example, domain_name\user_name) instead of isolated names (for example, user_name). Fully qualified names are unambiguous and provide better performance when the lookup is performed. This function also supports fully qualified DNS names (for example, example.example.com\user_name) and [user principal names](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) (for example, someone@example.com).

In addition to looking up local accounts, local domain accounts, and explicitly trusted domain accounts, **LookupAccountName** can look up the name for any account in any domain in the forest.

> [!NOTE]
> The winbase.h header defines LookupAccountName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EqualPrefixSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid)

[GetUserName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getusernamea)

[LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida)

[LsaLookupNames2](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupnames2)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use)