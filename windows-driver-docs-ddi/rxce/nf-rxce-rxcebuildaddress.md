# RxCeBuildAddress function

## Description

**RxCeBuildAddress** associates a transport address with a transport binding.

## Parameters

### `pAddress` [in, out]

On input, this parameter contains a pointer to an uninitialized RDBSS connection engine address structure. On output when this call is successful, the data members in the RXCE_ADDRESS structure will be properly initialized.

### `pTransport` [in]

A pointer to the transport with which this address is to be associated.

### `pTransportAddress` [in]

A pointer to the transport address to be associated with the binding.

### `pHandler` [in]

A pointer to the event handler associated with the registration.

### `pEventContext` [in]

A pointer to the context parameter to be passed back to the event handler.

## Return value

**RxCeBuildAddress** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to **RxCeBuildAddress** was invalid. |

## Remarks

When **RxCeBuildAddress** is successful, the data members in the RXCE_ADDRESS structure pointed to by the *pAddress* parameter will be properly initialized.

## See also

[RxCeTearDownAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownaddress)