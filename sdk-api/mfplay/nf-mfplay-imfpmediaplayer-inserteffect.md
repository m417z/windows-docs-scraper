# IMFPMediaPlayer::InsertEffect

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Applies an audio or video effect to playback.

## Parameters

### `pEffect` [in]

Pointer to the **IUnknown** interface for one of the following:

* A Media Foundation transform (MFT) that implements the effect. MFTs expose the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.
* An activation object that creates an MFT. Activation objects expose the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface.

### `fOptional` [in]

Specifies whether the effect is optional.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The effect is optional. If the MFPlay player object cannot add the effect, it ignores the effect and continues playback. |
| ****FALSE**** | If the MFPlay player object cannot add the effect, a playback error occurs. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDINDEX**** | This effect was already added. |

## Remarks

The object specified in the *pEffect* parameter can implement either a video effect or an audio effect. The effect is applied to any media items set after the method is called. It is not applied to the current media item.

For each media item, the effect is applied to the first selected stream of the matching type (audio or video). If a media item has two selected streams of the same type, the second stream does not receive the effect. The effect is ignored if the media item does not contain a stream that matches the effect type. For example, if you set a video effect and play a file that contains just audio, the video effect is ignored, although no error is raised.

The effect is applied to all subsequent media items, until the application removes the effect. To remove an effect, call [IMFPMediaPlayer::RemoveEffect](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-removeeffect) or [IMFPMediaPlayer::RemoveAllEffects](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-removealleffects).

If you set multiple effects of the same type (audio or video), they are applied in the same order in which you call **InsertEffect**.

### Remote Playback Optimizations

Audio and video effects might be incompatible with optimizations that are used for remote playback. The following remarks apply only to audio or video effects that are actually used during playback:

* If you mark an audio or video effect as required, by setting *fOptional* to **FALSE**, MFPlay disables remote playback optimizations.
* Otherwise, if all audio/video effects are marked as optional, MFPlay might drop the effects, in order to enable remote playback optimizations.

In other words, required effects have priority over remote optimizations, but optional effects do not.

Remote optimizations might be disabled for other reasons. For example, they are disabled if you set the **MFP_OPTION_NO_REMOTE_DESKTOP_OPTIMIZATION** option when you create the player object. In that case, MFPlay will attempt to insert any optional effects.

Non-audio, non-video effects do not affect remote optimizations. Also, if you insert a required effect but the source does not contain any streams of that type, remote optimizations are not disabled.

#### Examples

```cpp
HRESULT AddPlaybackEffect(REFGUID clsid, IMFPMediaPlayer *pPlayer)
{
    IMFTransform *pMFT = NULL;

    HRESULT hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&pMFT));

    if (SUCCEEDED(hr))
    {
        hr = pPlayer->InsertEffect(pMFT, TRUE); // Set as optional.
    }

    SafeRelease(&pMFT);
    return hr;
}

```

## See also

[How to Add Audio or Video Effects](https://learn.microsoft.com/windows/desktop/medfound/how-to-add-audio-or-video-effects)

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)