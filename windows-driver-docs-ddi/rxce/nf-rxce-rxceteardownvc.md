# RxCeTearDownVC function

## Description

**RxCeTearDownVC** deregisters a virtual circuit from a specified RDBSS connection.

## Parameters

### `pVc` [in]

A pointer to a handle for a virtual circuit structure to be torn down.

## Return value

**RxCeTearDownVC** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |

## Remarks

When **RxCeTearDownVC** is successful, the data members in the RXCE_VC structure pointed to by the *pVC* parameter will be properly uninitialized and the virtual circuit will be disconnected from the associated RDBSS transport, address, and connection.

Note that **RxCeTearDownVC** will wait for the clean up of connections over other transports to be completed before returning.

**RxCeTearDownVC** calls TDI to disconnect the virtual circuit associated with a connection. If the call to TDI is unsuccessful, **RxCeTearDownVC** will return the error from the TDI routine call.

## See also

[RxCeBuildVC](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildvc)