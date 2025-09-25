# WICPngBkgdProperties enumeration

## Description

Specifies the Portable Network Graphics (PNG) background (bKGD) chunk metadata properties.

## Constants

### `WICPngBkgdBackgroundColor:0x1`

Indicates the background color. There are three possible types, depending on the image's pixel format.

#### VT_UI1

Specifies the index of the background color in an image with an indexed pixel format.

#### VT_UI2

Specifies the background color in a grayscale image.

#### VT_VECTOR|VT_UI2

Specifies the background color in an RGB image as three USHORT values: {0x*RRRR*, 0x*GGGG*, 0x*BBBB*}.

### `WICPngBkgdProperties_FORCE_DWORD:0x7fffffff`