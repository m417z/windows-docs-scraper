# IWMResizerProps::GetFullCropRegion

## Description

Retrieves the source and destination rectangles.

## Parameters

### `lClipOriXSrc` [out]

Receives the left edge of the source rectangle, in pixels.

### `lClipOriYSrc` [out]

Receives the top edge of the source rectangle, in pixels.

### `lClipWidthSrc` [out]

Receives the width of the source rectangle, in pixels.

### `lClipHeightSrc` [out]

Receives the height of the source rectangle, in pixels.

### `lClipOriXDst` [out]

Receives the left edge of the destination rectangle, in pixels.

### `lClipOriYDst` [out]

Receives the top edge of the destination rectangle, in pixels.

### `lClipWidthDst` [out]

Receives the width of the destination rectangle, in pixels.

### `lClipHeightDst` [out]

Receives the height of the destination rectangle, in pixels.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMResizerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresizerprops)