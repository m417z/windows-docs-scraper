# WICRawRenderMode enumeration

## Description

Specifies the render intent of the next [CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) call.

## Constants

### `WICRawRenderModeDraft:0x1`

Use speed priority mode.

### `WICRawRenderModeNormal:0x2`

Use normal priority mode. Balance of speed and quality.

### `WICRawRenderModeBestQuality:0x3`

Use best quality mode.

### `WICRAWRENDERMODE_FORCE_DWORD:0x7fffffff`