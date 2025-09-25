# NetAccessGetUserPerms function

## Description

[This function is obsolete. For a list of alternate functions, see [Authorization Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions).]

Not supported.

 The
**NetAccessGetUserPerms** function returns a specified user's or group's access permissions for a particular resource.

## Parameters

### `servername`

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `UGname`

Pointer to a string that specifies the name of the user or group to query.

### `resource`

Pointer to a string that contains the name of the network resource to query.

### `Perms`

Pointer to an unsigned short integer that receives the user permissions for the specified resource.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function requires Admin privilege to successfully execute on a computer that has local security enabled. When users request their own access permissions, no special privilege is required.

## See also

[Authorization Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)