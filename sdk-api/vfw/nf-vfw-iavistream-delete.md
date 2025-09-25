# IAVIStream::Delete

## Description

The **Delete** method deletes data from a stream.

## Parameters

### `lStart`

Starting sample or frame number to delete.

### `lSamples`

Number of samples to delete.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Delete** has the following syntax:

```cpp

HRESULT Delete(LONG lStart, LONG lSamples);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)