# AVIStreamEndTime macro

## Syntax

```cpp
LONG AVIStreamEndTime(
     pavi
);
```

## Return value

Type: **LONG**

Returns the time if successful or -1 otherwise.

## Description

The **AVIStreamEndTime** macro returns the time representing the end of the stream.

## Parameters

### `pavi`

Handle to an open stream.

## Remarks

The **AVIStreamEndTime** macro is defined as follows:

```cpp

#define AVIStreamEndTime(pavi) \
    AVIStreamSampleToTime(pavi, AVIStreamEnd(pavi))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)