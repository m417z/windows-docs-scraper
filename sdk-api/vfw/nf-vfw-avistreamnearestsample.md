# AVIStreamNearestSample macro

## Syntax

```cpp
LONG AVIStreamNearestSample(
     pavi,
     l
);
```

## Return value

Type: **LONG**

Returns the sample position if successful or -1 otherwise.

## Description

The **AVIStreamNearestSample** macro locates the nearest nonempty sample at or preceding a specified position in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Starting position to search in the stream.

## Remarks

The **AVIStreamNearestSample** macro is defined as follows:

```cpp

#define AVIStreamNearestSample(pavi, l) \
    AVIStreamFindSample(pavi, l, FIND_PREV | FIND_ANY)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)