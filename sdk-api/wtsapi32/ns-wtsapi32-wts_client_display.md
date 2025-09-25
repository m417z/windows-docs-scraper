# WTS_CLIENT_DISPLAY structure

## Description

Contains information about the display of a Remote Desktop Connection (RDC) client.

## Members

### `HorizontalResolution`

Horizontal dimension, in pixels, of the client's display.

### `VerticalResolution`

Vertical dimension, in pixels, of the client's display.

### `ColorDepth`

Color depth of the client's display. This member can be one of the following values.

#### 1

4 bits per pixel.

#### 2

8 bits per pixel.

#### 4

16 bits per pixel.

#### 8

A 3-byte RGB values for a maximum of 2^24 colors.

#### 16

15 bits per pixel.

#### 24

24 bits per pixel.

#### 32

32 bits per pixel.

## See also

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)