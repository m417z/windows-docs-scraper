# IAVIStream::FindSample

## Description

The **FindSample** method obtains the position in a stream of a key frame or a nonempty frame. Called when an application uses the [AVIStreamFindSample](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamfindsample) function.

## Parameters

### `lPos`

Position of the sample or frame.

### `lFlags`

Applicable flags. The following values are defined.

| Value | Description |
| --- | --- |
| FIND_ANY | Searches for a nonempty frame. |
| FIND_FORMAT | Searches for a format change. |
| FIND_KEY | Searches for a key frame. |
| FIND_NEXT | Searches forward through a stream, beginning with the current frame. |
| FIND_PREV | Searches backward through a stream, beginning with the current frame. |

The FIND_ANY, FIND_KEY, and FIND_FORMAT flags are mutually exclusive, as are the FIND_NEXT and FIND_PREV flags. You must specify one value from each group.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the location of the key frame corresponding to the frame specified by the application.

## Remarks

If key frames are not significant in your custom format, return the position specified for *lPos*.

For handlers written in C++, **FindSample** has the following syntax:

```cpp

LONG FindSample(LONG lPos, LONG lFlags)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)