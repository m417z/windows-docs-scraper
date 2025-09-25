# IAVIEditStream::Copy

## Description

The **Copy** method copies a stream or a portion of it to a temporary stream. Called when an application uses the [EditStreamCopy](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-editstreamcopy) function.

## Parameters

### `plStart`

Pointer to a buffer that receives the starting position of the operation.

### `plLength`

Pointer to a buffer that receives the length, in frames, of the operation.

### `ppResult`

Pointer to a buffer that receives a pointer to the interface to the new stream.

#### - pavi

Pointer to the interface to the stream to copy.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Copy** has the following syntax:

```cpp

HRESULT Copy(LONG *plStart, LONG *plLength,
    PAVISTREAM * ppResult);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)