## Description

The QueryHostContextExtension method provides a way to lookup a context extension and its information using an identifier GUID.

## Parameters

### `identifier`

A REFGUID value that represents the identifier GUID of the extension.
blobId

### `blobId`

A pointer to an output ULONG variable that receives the unique identifier of the data blob associated with the queried context extension.

### `blobSize`

A pointer to an output ULONG variable that receives the size of the data blob associated with the queried context extension.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostExtensibility3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility3)