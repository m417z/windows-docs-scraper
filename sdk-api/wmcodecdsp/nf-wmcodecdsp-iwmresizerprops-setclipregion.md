# IWMResizerProps::SetClipRegion

## Description

Sets the source rectangle.

## Parameters

### `lClipOriXSrc` [in]

Specifies the left edge of the source rectangle, in pixels.

### `lClipOriYSrc` [in]

Specifies the top edge of the source rectangle, in pixels.

### `lClipWidthSrc` [in]

Specifies the width of the source rectangle, in pixels.

### `lClipHeightSrc` [in]

Specifies the height of the source rectangle, in pixels.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

By default, the video resizer copies the entire video frame. When you call this method, the video resizer crops the video to the source rectangle and copies that portion to the output buffer.

This method is equivalent to setting the following properties:

* [MFPKEY_RESIZE_SRC_LEFT](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-src-left)
* [MFPKEY_RESIZE_SRC_TOP](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-src-top)
* [MFPKEY_RESIZE_SRC_WIDTH](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-src-width)
* [MFPKEY_RESIZE_SRC_HEIGHT](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-src-height)

## See also

[IWMResizerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresizerprops)