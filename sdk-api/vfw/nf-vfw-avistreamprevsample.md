# AVIStreamPrevSample macro

## Syntax

```cpp
LONG AVIStreamPrevSample(
     pavi,
     l
);
```

## Return value

Type: **LONG**

Returns the sample position if successful or –1 otherwise.

## Description

The **AVIStreamPrevSample** macro locates the nearest nonempty sample that precedes a specified position in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Starting position to search in the stream.

## Remarks

The sample position returned does not include the sample specified by *l*.

The **AVIStreamPrevSample** macro is defined as follows:

```cpp

#define AVIStreamPrevSample(pavi, l) \
    AVIStreamFindSample(pavi, l - 1, FIND_PREV | FIND_ANY)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)