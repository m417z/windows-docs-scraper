# RxCeBuildTransport function

## Description

**RxCeBuildTransport** binds an RDBSS transport object to a specified transport name.

## Parameters

### `pRxCeTransport`

On input, this parameter contains a pointer to an uninitialized RDBSS transport with which this transport name is to be associated. On output when this call is successful, the transport is associated with the specified transport name and the transport is properly initialized.

### `pTransportName` [in]

A pointer to the Unicode binding string for the desired transport.

### `QualityOfService` [in]

The quality of service desired from the transport.

## Return value

**RxCeBuildTransport** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |

## Remarks

When **RxCeBuildTransport** is successful, the data members in the RXCE_TRANSPORT structure pointed to by the *pTransport* parameter will be properly initialized and the RDBSS transport will be bound to the specified TDI transport.

The connection engine routines in RDBSS do not participate in the computation of quality of service. RDBSS essentially uses the *QualityOfService* parameter as a magic number that is passed to the underlying transport provider.

## See also

[RxCeTearDownTransport](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardowntransport)