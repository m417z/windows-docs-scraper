# XAudio2CreateReverb function

## Description

Creates a new reverb audio processing object (APO), and returns a pointer to it.

## Parameters

### `ppApo` [in, out]

Contains a pointer to the reverb APO that is created.

### `DEFAULT` [in]

Flags that specify the behavior of the APO. The value of this parameter must be 0.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**XAudio2CreateReverb** creates an effect performing Princeton Digital Reverb. The XAPO effect library (XAPOFX) includes an alternate reverb effect. Use [CreateFX](https://learn.microsoft.com/windows/desktop/api/xapofx/nf-xapofx-createfx) to create this alternate effect.

The reverb APO supports has the following restrictions:

* Input audio data must be FLOAT32.
* Framerate must be within XAUDIO2FX_REVERB_MIN_FRAMERATE (20,000 Hz) and XAUDIO2FX_REVERB_MAX_FRAMERATE (48,000 Hz).
* The input and output channels must be one of the following combinations.
  + Mono input and mono output
  + Mono input and 5.1 output
  + Stereo input and stereo output
  + Stereo input and 5.1 output

The reverb APO maintains internal state information between processing samples. You can only use an instance of the APO with one source of audio data at a time. Multiple voices that require reverb effects would each need to create a separate reverb effect with **XAudio2CreateReverb**.

For information about creating new effects for use with XAudio2, see the [XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview).

| Windows |
| --- |
| Because **XAudio2CreateReverb** calls **CoCreateInstance** on Windows, the application must have called the **CoInitializeEx** method before calling **XAudio2CreateReverb**. [XAudio2Create](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2create) has the same requirement, which means **CoInitializeEx** typically will be called long before **XAudio2CreateReverb** is called.<br><br>A typical calling pattern on Windows would be as follows:<br><br>``` #ifndef _XBOX CoInitializeEx(NULL, COINIT_MULTITHREADED); #endif IXAudio2* pXAudio2 = NULL; HRESULT hr; if ( FAILED(hr = XAudio2Create( &pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR ) ) ) return hr; ... IUnknown * pReverbAPO; XAudio2CreateReverb(&pReverbAPO);<br><br>``` |

The xaudio2fx.h header defines the **AudioReverb** class GUID as a cross-platform audio processing object (XAPO).

``` syntax
class __declspec(uuid("C2633B16-471B-4498-B8C5-4F0959E2EC09")) AudioReverb;

```

**XAudio2CreateReverb** returns this object as a pointer to a pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) in the *ppApo* parameter. Although you can query the [IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo) and [IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters) interfaces from this **IUnknown**, you typically never use these interfaces directly. Instead, you use them when you create a voice to add them as part of the effects chain.

The reverb uses the [XAUDIO2FX_REVERB_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_reverb_parameters) parameter structure that you access via the [IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters).

> [!NOTE]
> **XAudio2CreateReverb** is an inline function in xaudio2fx.h that calls **CreateAudioReverb** as illustrated in the following code example.

``` syntax
XAUDIO2FX_STDAPI CreateAudioReverb(_Outptr_ IUnknown** ppApo);
__inline HRESULT XAudio2CreateReverb(_Outptr_ IUnknown** ppApo, UINT32 /*Flags*/ DEFAULT(0))
{
    return CreateAudioReverb(ppApo);
}
```

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters)

[XAUDIO2FX_REVERB_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_reverb_parameters)

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)