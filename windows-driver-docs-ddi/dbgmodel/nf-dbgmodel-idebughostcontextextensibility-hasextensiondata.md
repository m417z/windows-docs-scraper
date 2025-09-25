## Description

This method is used to indicate whether a given context has a particular extension blob associated with it.

## Parameters

### `blobId`

This input parameter represents the id of the blob. The function will check to see if the context has this blob associated with it.

## Return value

Returns true if the given context has the specified extension blob associated with it, otherwise returns false.

## Remarks

The HasExtensionData() method is useful for checking if a specific extension blob is associated with a context before attempting to read the extension data with [ReadExtensionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostcontextextensibility-readextensiondata).

## See also

[IDebugHostContextExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextextensibility)