# DISPLAYCONFIG_DESKTOP_IMAGE_INFO structure

## Description

The DISPLAYCONFIG_DESKTOP_IMAGE_INFO structure contains information about the image displayed on the desktop.

## Members

### `PathSourceSize`

A [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the size of the VidPn source surface that is being displayed on the monitor.

### `DesktopImageRegion`

A [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines where the desktop image will be positioned within path source. Region must be completely inside the bounds of the path source size.

### `DesktopImageClip`

A [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines which part of the desktop image for this clone group will be displayed on this path. This currently must be set to the desktop size.