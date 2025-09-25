# IConfigAsfWriter2::StreamNumFromPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StreamNumFromPin` method retrieves the stream number associated with the specified input pin.

## Parameters

### `pPin` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface on the input pin.

### `pwStreamNum` [out]

Receives the stream number.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

You may need to use the Windows Media Format SDK interfaces directly to manipulate a stream before running the filter graph. This method is provided because you cannot assume that an ASF stream number is the same as the DirectShow pin number.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[IConfigAsfWriter2 Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter2)