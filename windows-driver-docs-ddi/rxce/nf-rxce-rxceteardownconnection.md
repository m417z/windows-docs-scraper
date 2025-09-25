# RxCeTearDownConnection function

## Description

**RxCeTearDownConnection** tears down a given connection between a local RDBSS connection address and a remote address.

## Parameters

### `pConnection` [in]

A pointer to a connection to be torn down.

## Return value

**RxCeTearDownConnection** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |

## Remarks

When **RxCeTearDownConnection** is successful, the data members in the RXCE_CONNECTION structure pointed to by the *pConnection* parameter will be properly uninitialized, and allocated memory for connection information and handler will be freed.

## See also

[RxCeBuildConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildconnection)