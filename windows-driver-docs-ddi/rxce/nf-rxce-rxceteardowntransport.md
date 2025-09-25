# RxCeTearDownTransport function

## Description

**RxCeTearDownTransport** unbinds an RDBSS transport object.

## Parameters

### `pTransport` [in]

A pointer to the RDBSS transport to be torn down.

## Return value

**RxCeTearDownTransport** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *pTransport* parameter passed to **RxCeTearDownAddress** or one of the data members associated with this transport was invalid. |

## Remarks

When **RxCeTearDownTransport** is successful, the data members in the RXCE_TRANSPORT structure pointed to by the *pTransport* parameter will be properly uninitialized, the RDBSS transport will be released from the specified TDI transport, and allocated memory for name buffers and provider information will be freed.

If a transport that has not been bound to is specified in the *pTransport* parameter, no error is returned and the operation returns STATUS_SUCCESS.

## See also

[RxCeBuildTransport](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildtransport)