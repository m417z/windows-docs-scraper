# RxCeTearDownAddress function

## Description

**RxCeTearDownAddress** deregisters a transport address from a transport binding.

## Parameters

### `pAddress` [in]

A pointer to the RDBSS connection engine address to deregister.

## Return value

**RxCeTearDownAddress** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *pAddress* parameter passed to **RxCeTearDownAddress** or one of the data members associated with this address was invalid. |

## Remarks

When **RxCeTearDownAddress** is successful, the data members in the RXCE_ADDRESS structure pointed to by the *pAddress* parameter will be properly uninitialized, TDI addresses will be closed, and allocated memory for handlers and transport addresses will be freed.

## See also

[RxCeBuildAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildaddress)