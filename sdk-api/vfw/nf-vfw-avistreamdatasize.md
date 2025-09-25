# AVIStreamDataSize macro

## Syntax

```cpp
HRESULT AVIStreamDataSize(
     pavi,
     fcc,
     plSize
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns zero if successful or an error otherwise. The return value AVIERR_NODATA indicates the system could not find any data with the specified four-character code.

## Description

The **AVIStreamDataSize** macro determines the buffer size, in bytes, needed to retrieve optional header data for a specified stream.

## Parameters

### `pavi`

Handle to an open stream.

### `fcc`

Four-character code specifying the stream type.

### `plSize`

Address to contain the buffer size for the optional header data.

## Remarks

The **AVIStreamDataSize** macro is defined as follows:

```cpp

#define AVIStreamDataSize(pavi, fcc, plSize) \
    AVIStreamReadData(pavi, fcc, NULL, plSize)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)