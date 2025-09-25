# AVIStreamNearestKeyFrame macro

## Syntax

```cpp
LONG AVIStreamNearestKeyFrame(
     pavi,
     l
);
```

## Return value

Type: **LONG**

Returns the position of the key frame if successful or –1 otherwise.

## Description

The **AVIStreamNearestKeyFrame** macro locates the key frame at or preceding a specified position in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Starting position to search in the stream.

## Remarks

The **AVIStreamNearestKeyFrame** macro is defined as follows:

```cpp

#define AVIStreamNearestKeyFrame(pavi, l) \
    AVIStreamFindSample(pavi, l , FIND_PREV | FIND_KEY)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)