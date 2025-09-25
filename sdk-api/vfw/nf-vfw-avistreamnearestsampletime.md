# AVIStreamNearestSampleTime macro

## Syntax

```cpp
LONG AVIStreamNearestSampleTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time of the nearest sample if successful or –1 otherwise.

## Description

The **AVIStreamNearestSampleTime** macro determines the time corresponding to the beginning of a sample that is nearest to a specified time in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Starting time, in milliseconds, to search in the stream.

## Remarks

The **AVIStreamNearestSampleTime** macro is defined as follows:

```cpp

#define AVIStreamNearestSampleTime(pavi, t) \
    AVIStreamSampleToTime(pavi, AVIStreamNearestSample(pavi,
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)