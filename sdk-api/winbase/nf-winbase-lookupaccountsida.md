# LookupAccountSidA function

## Description

The **LookupAccountSid** function accepts a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) as input. It retrieves the name of the account for this SID and the name of the first domain on which this SID is found.

## Parameters

### `lpSystemName` [in, optional]

A pointer to a **null**-terminated character string that specifies the target computer. This string can be the name of a remote computer. If this parameter is **NULL**, the account name translation begins on the local system. If the name cannot be resolved on the local system, this function will try to resolve the name using domain controllers trusted by the local system. Generally, specify a value for *lpSystemName* only when the account is in an untrusted domain and the name of a computer in that domain is known.

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

The **LookupAccountSid** function attempts to find a name for the specified SID by first checking a list of well-known SIDs. If the supplied SID does not correspond to a well-known SID, the function checks built-in and administratively defined local accounts. Next, the function checks the primary domain. [Security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) not recognized by the primary domain are checked against the trusted domains that correspond to their SID prefixes.

If the function cannot find an account name for the SID, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NONE_MAPPED. This can occur if a network time-out prevents the function from finding the name. It also occurs for SIDs that have no corresponding account name, such as a [logon SID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) that identifies a [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

In addition to looking up SIDs for local accounts, local domain accounts, and explicitly trusted domain accounts, **LookupAccountSid** can look up SIDs for any account in any domain in the forest, including SIDs that appear only in the SIDhistory field of an account in the forest. The SIDhistory field stores former SIDs of an account that has been moved from another domain. To look up a SID, **LookupAccountSid** queries the global catalog of the forest.

#### Examples

For an example that uses this function, see [Searching for a SID in an Access Token](https://learn.microsoft.com/windows/desktop/SecAuthZ/searching-for-a-sid-in-an-access-token-in-c--).

> [!NOTE]
> The winbase.h header defines LookupAccountSid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EqualPrefixSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use)