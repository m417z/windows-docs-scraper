## Description

[This function is obsolete. For a list of alternate functions, see [Authorization Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions).]

Not supported.

The **NetAccessEnum** function retrieves information about each access permission record.

## Parameters

### `servername`

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `BasePath`

Pointer to a string that contains a base pathname for the resource. A **NULL** pointer or **NULL** string means no base path is to be used. The path can be specified as a universal naming convention (UNC) pathname.

### `Recursive`

Specifies a flag that enables or disables recursive searching.

If this parameter is equal to zero, the **NetAccessEnum** function returns entries for the resource named as the base path by the *pszBasePath* parameter, and for the resources directly below that base path.

If this parameter is nonzero, the function returns entries for all access control lists (ACLs) that have *pszBasePath* at the beginning of the resource name.

### `level`

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The *pbBuffer* parameter points to an **access_info_0** structure. |
| **1** | The *pbBuffer* parameter points to an **access_info_1** structure. |

### `bufptr`

Pointer to the buffer that receives the access information structure. The format of this data depends on the value of the *sLevel* parameter.

### `prefmaxlen`

Specifies the size, in bytes, of the buffer pointed to by the *pbBuffer* parameter.

### `entriesread`

Pointer to an unsigned short integer that receives the count of elements actually enumerated. The count is valid only if the
**NetAccessEnum** function returns **NERR_Success** or **ERROR_MORE_DATA**.

### `totalentries`

Pointer to an unsigned short integer that receives the total number of entries that could have been enumerated. The count is valid only if the
**NetAccessEnum** function returns **NERR_Success** or **ERROR_MORE_DATA**.

### `resume_handle`

TBD

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function requires Admin privilege to successfully execute on a computer that has local security enabled.

## See also

[Authorization functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)