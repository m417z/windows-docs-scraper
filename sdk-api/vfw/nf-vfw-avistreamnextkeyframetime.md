# AVIStreamNextKeyFrameTime macro

## Syntax

```cpp
LONG AVIStreamNextKeyFrameTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamNextKeyFrameTime** macro returns the time of the next key frame in the stream, starting at a given time.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Position in the stream to begin searching.

## Remarks

The search performed by this macro includes the frame that corresponds to the specified time.

The **AVIStreamNextKeyFrameTime** macro is defined as follows:

```cpp

#define AVIStreamNextKeyFrameTime(pavi, t) \
    AVIStreamSampleToTime(pavi, \
    AVIStreamNextKeyFrame(pavi, \
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)