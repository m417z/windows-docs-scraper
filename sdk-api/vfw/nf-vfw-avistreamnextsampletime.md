# AVIStreamNextSampleTime macro

## Syntax

```cpp
LONG AVIStreamNextSampleTime(
     pavi,
     t
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamNextSampleTime** macro returns the time that a sample changes to the next sample in the stream. This macro finds the next interesting time in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `t`

Position information of the sample in the stream.

## Remarks

The **AVIStreamNextSampleTime** macro is defined as follows:

```cpp

#define AVIStreamNextSampleTime(pavi, t) \
    AVIStreamSampleToTime(pavi, \
    AVIStreamNextSample(pavi, \
    AVIStreamTimeToSample(pavi, t)))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)