# KsDispatchSpecificProperty function

## Description

The **KsDispatchSpecificProperty** function dispatches the property to a specific handler. The function assumes that the caller has previously dispatched this IRP to a handler through the **KsPropertyHandler** function.

This function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp`

### `Handler`

## Return value

The **KsDispatchSpecificProperty** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns an error.

## Remarks

The **KsDispatchSpecificProperty** function is intended for additional processing of a property such as completing a pending operation.

## See also

[KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler)