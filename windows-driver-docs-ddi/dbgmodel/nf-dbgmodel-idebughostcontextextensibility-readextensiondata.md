## Description

This method reads a set of extension data from a host context. This method will fail if the context does not have the particular extension blob associated with it.

## Parameters

### `blobId`

This input parameter represents the id of the blob whose data will be read from the host context.

### `bufferSize`

This input parameter represents the size of the buffer which will be used to retrieve the data from the host context.

### `buffer`

This output parameter is a pointer that points to the buffer which will be populated with the data from the host context.

## Return value

If the method succeeds, it returns S_OK. If it fails due to the context not having the particular extension blob associated with it, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextextensibility)