# IGetFrame::GetFrame

## Description

The **GetFrame** method retrieves a decompressed copy of a frame from a stream. Called when an application uses the [AVIStreamGetFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframe) function.

## Parameters

### `lPos`

Frame to copy and decompress.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the address of the decompressed frame data.

## Remarks

For handlers written in C++, **GetFrame** has the following syntax:

```cpp

LPVOID GetFrame(LONG lPos);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)