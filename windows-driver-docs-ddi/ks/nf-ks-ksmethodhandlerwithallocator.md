## Description

The **KsMethodHandlerWithAllocator** functions performs the same handling as **KsMethodHandler**, with the same restrictions, but allows an optional allocator callback to be used to provide a buffer for the parameters. If used, the filter may need to free the buffer in some nonconventional manner. Note that the IRP_BUFFERED_IO and IRP_DEALLOCATE_BUFFER flags are not set when using a custom allocator.

## Parameters

### `Irp` [in]

Specifies the IRP with the method request being handled.

### `MethodSetsCount` [in]

Indicates the number of method set structures being passed.

### `MethodSet` [in]

Specifies the pointer to the list of method set information.

### `Allocator` [in, optional]

Optionally points to an allocation function that will be used to allocate memory to store the method parameters.

### `MethodItemSize` [in, optional]

Optionally contains the size of each KSMETHOD_ITEM structure in each list of methods. The method item may be extended in order to store private information. If this parameter is zero, the structure size is assumed to be normal. If it is greater than or equal to a method item structure, the KSMETHOD_ITEM_IRP_STORAGE macro can be used to return a pointer to the method item so the custom data can be retrieved. On 64-bit platforms, this parameter must be a multiple of 8.

## Return value

The **KsMethodHandler** function returns STATUS_SUCCESS if successful, or an error specific to the method being handled if unsuccessful. The function always sets the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP to zero because of an internal error, or the element is set by a method handler. The function does not set the IO_STATUS_BLOCK.Status field nor complete the IRP.

On 64-bit platforms, if the *PropertyItemSize* parameter is not a multiple of 8, STATUS_INVALID_PARAMETER is returned, and the call fails.