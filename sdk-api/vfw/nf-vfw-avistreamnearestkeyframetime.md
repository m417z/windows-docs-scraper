# AVIStreamNearestKeyFrameTime macro

## Syntax

```cpp
LONG AVIStreamNearestKeyFrameTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time of the nearest key frame if successful or –1 otherwise.

## Description

The **AVIStreamNearestKeyFrameTime** macro determines the time corresponding to the beginning of the key frame nearest (at or preceding) a specified time in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Starting time, in milliseconds, to search in the stream.

## Remarks

The **AVIStreamNearestKeyFrameTime** macro is defined as follows:

```cpp

#define AVIStreamNearestKeyFrameTime(pavi, t) \
    AVIStreamSampleToTime(pavi, AVIStreamNearestKeyFrame(pavi,
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)