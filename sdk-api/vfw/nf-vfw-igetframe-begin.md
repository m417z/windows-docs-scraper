# IGetFrame::Begin

## Description

The **Begin** method prepares to extract and decompress copies of frames from a stream. Called when an application uses the [AVIStreamGetFrameOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframeopen) function.

## Parameters

### `lStart`

Starting frame for extracting and decompressing.

### `lEnd`

Ending frame for extracting and decompressing.

### `lRate`

Speed at which the file is read relative to its normal playback rate. Normal speed is 1000. Larger values indicate faster speeds; smaller values indicate slower speeds.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **Begin** has the following syntax:

```cpp

HRESULT Begin(LONG lStart, LONG lEnd, LONG lRate);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)