# KsMethodHandler function

## Description

The **KsMethodHandler** function handles methods requested through IOCTL_KS_METHOD. It works with all method identifiers defined by the sets. The function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP with the method request being handled.

### `MethodSetsCount` [in]

Indicates the number of method set structures being passed.

### `MethodSet` [in]

Specifies the pointer to the list of method set information.

## Return value

The **KsMethodHandler** function returns STATUS_SUCCESS if successful, or an error specific to the method being handled if unsuccessful. The function always sets the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP to zero because of an internal error, unless the element is set by a method handler. The function does not set the IO_STATUS_BLOCK.Status field nor complete the IRP.

## Remarks

The owner of a method set can perform prefiltering or postfiltering of the method handling using the **KsMethodHandler** and **KsFastMethodHandler** functions.

## See also

[KsFastMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfastmethodhandler)

[KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator)