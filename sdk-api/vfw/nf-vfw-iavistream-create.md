# IAVIStream::Create

## Description

The **Create** method initializes a stream handler that is not associated with any file. Called when an application uses the [AVIStreamCreate](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamcreate) function.

## Parameters

### `lParam1`

Stream handler-specific data.

### `lParam2`

Stream handler-specific data.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Create** has the following syntax:

```cpp

HRESULT Create(LONG lParam1, LONG lParam2)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)