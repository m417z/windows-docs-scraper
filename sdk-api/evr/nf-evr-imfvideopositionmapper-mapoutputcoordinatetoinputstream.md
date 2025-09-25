# IMFVideoPositionMapper::MapOutputCoordinateToInputStream

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Maps output image coordinates to input image coordinates. This method provides the reverse transformation for components that map coordinates on the input image to different coordinates on the output image.

## Parameters

### `xOut` [in]

X-coordinate of the output image, normalized to the range [0...1].

### `yOut` [in]

Y-coordinate of the output image, normalized to the range [0...1].

### `dwOutputStreamIndex` [in]

Output stream index for the coordinate mapping.

### `dwInputStreamIndex` [in]

Input stream index for the coordinate mapping.

### `pxIn` [out]

Receives the mapped x-coordinate of the input image, normalized to the range [0...1].

### `pyIn` [out]

Receives the mapped y-coordinate of the input image, normalized to the range [0...1].

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## Remarks

In the following diagram, R(dest) is the destination rectangle for the video. You can obtain this rectangle by calling [IMFVideoDisplayControl::GetVideoPosition](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-getvideoposition). The rectangle R1 is a substream within the video. The point P has pixel coordinates (x,y) relative to R(dest).

![Illustration showing a rectangle labeled R dest surrounding one labeled R1, which contains a point P located at (x,y)](https://learn.microsoft.com/windows/win32/api/evr/images/imfvideopositionmapper.gif)

The position of P relative to R(dest) in *normalized* coordinates is calculated as follows:

``` syntax
float xn = float(x + 0.5) / widthDest;
float xy = float(y + 0.5) / heightDest;

```

where *widthDest* and *heightDest* are the width and height of R(dest) in pixels.

To calculate the position of P relative to R1, call **MapOutputCoordinateToInputStream** as follows:

``` syntax
float x1 = 0, y1 = 0;
hr = pMap->MapOutputCoordinateToInputStream(xn, yn, 0, dwInputStreamIndex, &x1, &y1);
```

The values returned in *x1* and *y1* are normalized to the range [0...1]. To convert back to pixel coordinates, scale these values by the size of R1:

``` syntax
int scaledx = int(floor(x1 * widthR1));
int scaledy = int(floor(xy * heightR1));
```

Note that *x1* and *y1* might fall outside the range [0...1] if P lies outside of R1.

## See also

[IMFVideoPositionMapper](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopositionmapper)