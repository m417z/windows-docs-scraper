# mmioFOURCC macro

## Syntax

```cpp
FOURCC mmioFOURCC(
    CHAR ch0,
    CHAR ch1,
    CHAR ch2,
    CHAR ch3
);
```

## Return value

Type: **FOURCC**

Returns the four-character code created from the given characters.

## Description

The **mmioFOURCC** macro converts four characters into a four-character code.

## Parameters

### `ch0`

First character of the four-character code.

### `ch1`

Second character of the four-character code.

### `ch2`

Third character of the four-character code.

### `ch3`

Fourth character of the four-character code.

## Remarks

This macro does not check whether the four-character code it returns is valid.

The **mmioFOURCC** macro is defined as follows:

```cpp

#define mmioFOURCC(ch0, ch1, ch2, ch3) \
    MAKEFOURCC(ch0, ch1, ch2, ch3);

```

The **MAKEFOURCC** macro, in turn, is defined as follows:

```cpp

#define MAKEFOURCC(ch0, ch1, ch2, ch3)  \
    ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |  \
    ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ));

```