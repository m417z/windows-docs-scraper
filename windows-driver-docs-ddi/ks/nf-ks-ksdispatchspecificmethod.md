# KsDispatchSpecificMethod function

## Description

The **KsDispatchSpecificMethod** function dispatches a method to a specific handler. The function assumes that the caller has previously dispatched the IRP to a handler through the **KsMethodHandler** function.

The function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP with the method request being dispatched.

### `Handler` [in]

Specifies the pointer to the specific method handler.

## Return value

The **KsDispatchSpecificMethod** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns an error.

## Remarks

The **KsDispatchSpecificMethod** function is intended for additional processing of the method such as completing a pending operation.

## See also

[KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler)