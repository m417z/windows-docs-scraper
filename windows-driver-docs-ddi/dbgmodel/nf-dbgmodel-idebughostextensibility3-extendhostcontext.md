## Description

The ExtendHostContext method is used by hosts which support receiving arbitrary plain old data (POD) inside a host context. This method extends the notion of a host context with a specific size of POD data.

## Parameters

### `blobSize`

A ULONG variable that indicates the size of the data blob to be stored in the host context.
identifier

### `identifier`

A REFGUID value that provides an identifier for the host context that gets extended.

### `blobId`

A pointer to an output ULONG variable that is used to receive a unique identifier that can be used to set and retrieve the data on any host context object.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The data stored inside a host context must be plain intrinsic data: it cannot be a COM interface; it cannot be anything which requires destruction, and it should be as small as possible.

Unless the data is explicitly added via the [IDebugHostContextExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility) method, no host context will contain such data.

## See also

[IDebugHostExtensibility3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility3)