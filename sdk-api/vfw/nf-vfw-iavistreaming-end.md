# IAVIStreaming::End

## Description

The **End** method ends the streaming operation. Called when an application uses the [AVIStreamEndStreaming](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamendstreaming) function.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **End** has the following syntax:

```cpp

HRESULT End(VOID);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)