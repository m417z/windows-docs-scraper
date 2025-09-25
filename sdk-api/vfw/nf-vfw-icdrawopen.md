# ICDrawOpen macro

## Syntax

```cpp
HIC ICDrawOpen(
    DWORD fccType,
    DWORD fccHandler,
    LPBITMAPINFOHEADER lpbiIn
);
```

## Return value

Type: **HIC**

Returns a handle of a driver if successful or zero otherwise.

## Description

The **ICDrawOpen** macro opens a driver that can draw images with the specified format.

## Parameters

### `fccType`

Four-character code indicating the type of driver to open. For video streams, the value of this parameter is "VIDC" or ICTYPE_VIDEO.

### `fccHandler`

Four-character code indicating the preferred stream handler to use. Typically, this information is stored in the stream header in an AVI file.

### `lpbiIn`

Pointer to the structure defining the input format. A driver handle will not be returned unless it can decompress this format. For images, this parameter refers to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

## Remarks

The **ICDrawOpen** macro is defined as follows:

```cpp

#define ICDrawOpen(fccType, fccHandler, lpbiIn) \
    ICLocate(fccType, fccHandler, lpbiIn, NULL, ICMODE_DRAW);

```

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)