# IAVIEditStream::Paste

## Description

The **Paste** method copies a stream or a portion of it in another stream. Called when an application uses the [EditStreamPaste](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-editstreampaste) function.

## Parameters

### `plPos`

Pointer to a buffer that receives the starting position of the operation.

### `plLength`

Pointer to a buffer that receives the length, in bytes, of the data to paste from the source stream.

### `pstream`

Pointer to the interface to the source stream.

### `lStart`

Starting position of the copy operation within the source stream.

### `lEnd`

Ending position of the copy operation within the source stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Paste** has the following syntax:

```cpp

HRESULT Paste(LONG *plPos, LONG *plLength,
    PAVISTREAM pstream, LONG lStart, LONG lLength);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)