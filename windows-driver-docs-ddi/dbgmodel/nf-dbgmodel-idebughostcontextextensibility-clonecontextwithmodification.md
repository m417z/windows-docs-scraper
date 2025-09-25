## Description

This method clones the current host context, associates a particular extension blob with the cloned context, finalizes the context, and returns an immutable interface to the newly cloned context.

## Parameters

### `blobId`

This input parameter represents the id of the blob that will be associated with the cloned context.

### `dataSize`

This input parameter represents the size of the data to be associated with the cloned context.

### `data`

This input parameter is a pointer that points to the actual data to be associated with the cloned context.

### `clonedContext`

This parameter points to a IDebugHostContext pointer, which retrieves the cloned context. This is an Output parameter for the cloned context.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextextensibility)