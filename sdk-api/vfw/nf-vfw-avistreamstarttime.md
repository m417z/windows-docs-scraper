# AVIStreamStartTime macro

## Syntax

```cpp
LONG AVIStreamStartTime(
     pavi
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamStartTime** macro returns the starting time of a stream's first sample.

## Parameters

### `pavi`

Handle to an open stream.

## Remarks

The **AVIStreamStartTime** macro is defined as follows:

```cpp

#define AVIStreamStartTime(pavi) \
    AVIStreamSampleToTime(pavi, AVIStreamStart(pavi))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)