# IAVIEditStream::Clone

## Description

The **Clone** method duplicates a stream. Called when an application uses the [EditStreamClone](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-editstreamclone) function.

## Parameters

### `ppResult`

Pointer to a buffer that receives a pointer to the interface to the new stream.

#### - pavi

Pointer to the interface to the stream being cloned.

## Return value

The method returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Clone** has the following syntax:

```cpp

HRESULT Clone(PAVISTREAM *ppResult);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)