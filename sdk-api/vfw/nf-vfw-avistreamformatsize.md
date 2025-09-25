# AVIStreamFormatSize macro

## Syntax

```cpp
HRESULT AVIStreamFormatSize(
     pavi,
     lPos,
     plSize
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns zero if successful or an error otherwise.

## Description

The **AVIStreamFormatSize** macro determines the buffer size, in bytes, needed to store format information for a sample in a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `lPos`

Position of a sample in the stream.

### `plSize`

Address to contain the buffer size.

## Remarks

The **AVIStreamFormatSize** macro is defined as follows:

```cpp

#define AVIStreamFormatSize(pavi, lPos, plSize) \
    AVIStreamReadFormat(pavi, lPos, NULL, plSize)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)