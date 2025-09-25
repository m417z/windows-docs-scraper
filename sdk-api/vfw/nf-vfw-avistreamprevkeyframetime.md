# AVIStreamPrevKeyFrameTime macro

## Syntax

```cpp
LONG AVIStreamPrevKeyFrameTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamPrevKeyFrameTime** macro returns the time of the previous key frame in the stream, starting at a given time.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Position in the stream to begin searching.

## Remarks

The search performed by this macro includes the frame that corresponds to the specified time.

The **AVIStreamPrevKeyFrameTime** macro is defined as follows:

```cpp

#define AVIStreamPrevKeyFrameTime(pavi, t) \
    AVIStreamSampleToTime(pavi, AVIStreamPrevKeyFrame(pavi,
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)