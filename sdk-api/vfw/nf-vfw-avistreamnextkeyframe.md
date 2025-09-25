# AVIStreamNextKeyFrame macro

## Syntax

```cpp
LONG AVIStreamNextKeyFrame(
     pavi,
     l
);
```

## Return value

Type: **LONG**

Returns the position of the key frame if successful or –1 otherwise.

## Description

The **AVIStreamNextKeyFrame** macro locates the next key frame following a specified position in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Starting position to search in the stream.

## Remarks

The search performed by this macro does not include the frame at the specified position.

The **AVIStreamNextKeyFrame** macro is defined as follows:

```cpp

#define AVIStreamNextKeyFrame(pavi, l) \
    AVIStreamFindSample(pavi, l + 1, FIND_NEXT | FIND_KEY)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)