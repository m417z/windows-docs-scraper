## Description

[This function is obsolete. For a list of alternate functions, see [Authorization Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions).]

Not supported.

The **NetAccessSetInfo** function changes the access control list (ACL) for a resource.

## Parameters

### `servername`

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `resource`

Pointer to a string that contains the name of the network resource to modify.

### `level`

Specifies the information level of the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **1** | The *pbBuffer* parameter points to an **access_info_1** structure. |

### `buf`

Pointer to the buffer that contains the access information structure. The format of this data depends on the value of the *sLevel* parameter.

### `parm_err`

TBD

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function requires Admin privilege to successfully execute on a computer that has local security enabled.

## See also

[Authorization functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)