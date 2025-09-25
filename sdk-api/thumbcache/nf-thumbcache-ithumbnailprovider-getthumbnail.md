# IThumbnailProvider::GetThumbnail

## Description

Gets a thumbnail image and alpha type.

## Parameters

### `cx` [in]

Type: **UINT**

The maximum thumbnail size, in pixels. The Shell draws the returned bitmap at this size or smaller. The returned bitmap should fit into a square of width and height *cx*, though it does not need to be a square image. The Shell scales the bitmap to render at lower sizes. For example, if the image has a 6:4 aspect ratio, then the returned bitmap should also have a 6:4 aspect ratio.

### `phbmp` [out]

Type: **HBITMAP***

When this method returns, contains a pointer to the thumbnail image handle. The image must be a DIB section and 32 bits per pixel. The Shell scales down the bitmap if its width or height is larger than the size specified by *cx*. The Shell always respects the aspect ratio and never scales a bitmap larger than its original size.

### `pdwAlpha` [out]

Type: **WTS_ALPHATYPE***

When this method returns, contains a pointer to one of the following values from the WTS_ALPHATYPE enumeration:

#### WTSAT_UNKNOWN (0x0)

0x0. The bitmap is an unknown format. The Shell tries nonetheless to detect whether the image has an alpha channel.

#### WTSAT_RGB (0x1)

0x1. The bitmap is an RGB image without alpha. The alpha channel is invalid and the Shell ignores it.

#### WTSAT_ARGB (0x2)

0x2. The bitmap is an ARGB image with a valid alpha channel.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.