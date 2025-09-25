# CheckTokenMembershipEx function

## Description

The **CheckTokenMembershipEx** function determines whether the specified SID is enabled in the specified token.

## Parameters

### `TokenHandle` [in, optional]

A handle to an access token. If present, this token is checked for the SID. If not present, then the current effective token is used. This must be an impersonation token.

### `SidToCheck` [in]

A pointer to a SID structure. The function checks for the presence of this SID in the presence of the token.

### `Flags` [in]

Flags that affect the behavior of the function. Currently the only valid flag is CTMF_INCLUDE_APPCONTAINER which allows app containers to pass the call as long as the other requirements of the token are met, such as the group specified is present and enabled.

### `IsMember` [out]

**TRUE** if the SID is enabled in the token; otherwise, **FALSE**.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).