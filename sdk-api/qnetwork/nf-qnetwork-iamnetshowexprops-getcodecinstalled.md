# IAMNetShowExProps::GetCodecInstalled

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCodecInstalled` method queries whether a specified codec is installed on the local system.

## Parameters

### `CodecNum`

Specifies the codec to query, indexed from zero. Call **get_CodecCount** to obtain the number of codecs.

### `pCodecInstalled`

Pointer that receives a Boolean value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IAMNetShowExProps Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamnetshowexprops)

[IAMNetShowExProps::get_CodecCount](https://learn.microsoft.com/windows/desktop/api/qnetwork/nf-qnetwork-iamnetshowexprops-get_codeccount)