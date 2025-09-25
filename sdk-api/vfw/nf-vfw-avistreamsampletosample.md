# AVIStreamSampleToSample macro

## Syntax

```cpp
LONG AVIStreamSampleToSample(
     pavi1,
     pavi2,
     l
);
```

## Return value

Type: **LONG**

Returns the sample if successful or –1 otherwise.

## Description

The **AVIStreamSampleToSample** macro returns the sample in a stream that occurs at the same time as a sample that occurs in a second stream.

## Parameters

### `pavi1`

Handle to an open stream that contains the sample that is returned.

### `pavi2`

Handle to a second stream that contains the reference sample.

### `l`

Position information of the sample in the stream referenced by pavi2.

## Remarks

The **AVIStreamSampleToSample** macro is defined as follows:

```cpp

#define AVIStreamSampleToSample(pavi1, pavi2, l) \
    AVIStreamTimeToSample(pavi1, AVIStreamSampleToTime \
    (pavi2, l))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)