# AVIStreamPrevSampleTime macro

## Syntax

```cpp
LONG AVIStreamPrevSampleTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamPrevSampleTime** macro determines the time of the nearest nonempty sample that precedes a specified time in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Position information of the sample in the stream.

## Remarks

The **AVIStreamPrevSampleTime** macro is defined as follows:

```cpp

#define AVIStreamPrevSampleTime(pavi, t) \
    AVIStreamSampleToTime(pavi, \
    AVIStreamPrevSample(pavi, \
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)