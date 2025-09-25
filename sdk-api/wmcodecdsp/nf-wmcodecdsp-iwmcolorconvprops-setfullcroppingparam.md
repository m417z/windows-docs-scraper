# IWMColorConvProps::SetFullCroppingParam

## Description

Sets the source and destination rectangles.

## Parameters

### `lSrcCropLeft` [in]

Specifies the left edge of the source rectangle, in pixels.

### `lSrcCropTop` [in]

Specifies the top edge of the source rectangle, in pixels.

### `lDstCropLeft` [in]

Specifies the left edge of the destination rectangle, in pixels.

### `lDstCropTop` [in]

Specifies the top edge of the destination rectangle, in pixels.

### `lCropWidth` [in]

Specifies the width of the source and destination rectangles, in pixels.

### `lCropHeight` [in]

Specifies the height of the source and destination rectangles, in pixels.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

By default, the color converter copies the entire video frame. When you call this method, the color converter crops the video to the source rectangle and copies that portion to the destination rectangle.

This method is equivalent to setting the following properties:

* [MFPKEY_COLORCONV_SRCLEFT](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-srcleft)
* [MFPKEY_COLORCONV_SRCTOP](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-srctop)
* [MFPKEY_COLORCONV_DSTLEFT](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-dstleft)
* [MFPKEY_COLORCONV_DSTTOP](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-dsttop)
* [MFPKEY_COLORCONV_WIDTH](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-width)
* [MFPKEY_COLORCONV_HEIGHT](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-height)

## See also

[IWMColorConvProps](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcolorconvprops)