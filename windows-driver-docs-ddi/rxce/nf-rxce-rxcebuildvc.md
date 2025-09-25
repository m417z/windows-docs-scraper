# RxCeBuildVC function

## Description

**RxCeBuildVC** adds a virtual circuit to a specified RDBSS connection..

## Parameters

### `pVc` [in, out]

On input, this parameter contains a pointer to a handle for an uninitialized virtual circuit. On output when this call is successful, the virtual circuit is associated with the specified connection and the state of the virtual circuit is initialized as active.

### `Connection`

A pointer to the connection on which the virtual circuit is to be added.

## Return value

**RxCeBuildVC** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |

## Remarks

When **RxCeBuildVC** is successful, the data members in the RXCE_VC structure pointed to by the *pVC* parameter will be properly initialized and the virtual circuit will be added to the specified RDBSS connection.

## See also

[RxCeTearDownVC](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownvc)