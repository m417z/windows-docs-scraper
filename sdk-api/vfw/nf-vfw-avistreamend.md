# AVIStreamEnd macro

## Syntax

```cpp
LONG AVIStreamEnd(
     pavi
);
```

## Return value

Type: **LONG**

Returns the sample number associated with the end of a stream, or, if an error occurs, one less than the first sample or one less than the stream length.

## Description

The **AVIStreamEnd** macro calculates the sample associated with the end of a stream.

## Parameters

### `pavi`

Handle to an open stream.

## Remarks

The sample number returned is not a valid sample number for reading data. It represents the end of the file. (The end of the file is equal to the start of the file plus its length.)

The **AVIStreamEnd** macro is defined as follows:

```cpp

#define AVIStreamEnd(pavi) \
    (AVIStreamStart(pavi) + AVIStreamLength(pavi))

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)