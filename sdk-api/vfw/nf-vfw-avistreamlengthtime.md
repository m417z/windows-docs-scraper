# AVIStreamLengthTime macro

## Syntax

```cpp
LONG AVIStreamLengthTime(
     pavi
);
```

## Return value

Type: **LONG**

Returns the time if successful or –1 otherwise.

## Description

The **AVIStreamLengthTime** macro returns the length of a stream in time.

## Parameters

### `pavi`

Handle to an open stream.

## Remarks

The **AVIStreamLengthTime** macro is defined as follows:

```cpp

#define AVIStreamLengthTime(pavi) \
    AVIStreamSampleToTime(pavi, AVIStreamLength(pavi))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)