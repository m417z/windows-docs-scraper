# AVIStreamIsKeyFrame macro

## Syntax

```cpp
BOOL AVIStreamIsKeyFrame(
     pavi,
     l
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the sample is a key frame or **FALSE** otherwise.

## Description

The **AVIStreamIsKeyFrame** macro indicates whether a sample in a specified stream is a key frame.

## Parameters

### `pavi`

Handle to an open stream.

### `l`

Position to search in the stream.

## Remarks

The **AVIStreamIsKeyFrame** macro is defined as follows:

```cpp

#define AVIStreamIsKeyFrame(pavi, l) \
    (AVIStreamNearestKeyFrame(pavi, l) == 1)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)