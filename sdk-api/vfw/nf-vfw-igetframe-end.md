# IGetFrame::End

## Description

The **End** method ends frame extraction and decompression. Called when an application uses the [AVIStreamGetFrameClose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframeclose) function.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Begin** has the following syntax:

```cpp

HRESULT End(VOID);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)