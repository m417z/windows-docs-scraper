# AVIStreamNextSample macro

## Syntax

```cpp
LONG AVIStreamNextSample(
     pavi,
     l
);
```

## Return value

Type: **LONG**

Returns the sample position if successful or –1 otherwise.

## Description

The **AVIStreamNextSample** macro locates the next nonempty sample from a specified position in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Starting position to search in the stream.

## Remarks

The sample position returned does not include the sample specified by *l*.

The **AVIStreamNextSample** macro is defined as follows:

```cpp

#define AVIStreamNextSample(pavi, l) \
    AVIStreamFindSample(pavi, l + 1, FIND_NEXT | FIND_ANY)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)