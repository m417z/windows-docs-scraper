# XAudio2CreateVolumeMeter function

## Description

Creates a new volume meter audio processing object (APO) and returns a pointer to it.

## Parameters

### `ppApo` [in, out]

Contains the created volume meter APO.

### `DEFAULT` [in]

Flags that specify the behavior of the APO. The value of this parameter must be 0.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For information on creating new effects for use with XAudio2, see the [XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview).

| Windows |
| --- |
| Because **XAudio2CreateVolumeMeter** calls **CoCreateInstance** on Windows, the application must have called the **CoInitializeEx** method before calling **XAudio2CreateVolumeMeter**. [XAudio2Create](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2create) has the same requirement, which means **CoInitializeEx** typically will be called long before **XAudio2CreateVolumeMeter** is called.<br><br>A typical calling pattern on Windows would be as follows:<br><br>``` #ifndef _XBOX CoInitializeEx(NULL, COINIT_MULTITHREADED); #endif IXAudio2* pXAudio2 = NULL; HRESULT hr; if ( FAILED(hr = XAudio2Create( &pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR ) ) ) return hr; ... IUnknown * pVolumeMeterAPO; XAudio2CreateVolumeMeter(&pVolumeMeterAPO);<br><br>``` |

The xaudio2fx.h header defines the **AudioVolumeMeter** class GUID as a cross-platform audio processing object (XAPO).

``` syntax
class __declspec(uuid("4FC3B166-972A-40CF-BC37-7DB03DB2FBA3")) AudioVolumeMeter;

```

**XAudio2CreateVolumeMeter** returns this object as a pointer to a pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) in the *ppApo* parameter. Although you can query the [IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo) and [IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters) interfaces from this **IUnknown**, you typically never use these interfaces directly. Instead, you use them when you create a voice to add them as part of the effects chain.

The volume meter uses the [XAUDIO2FX_VOLUMEMETER_LEVELS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_volumemeter_levels) parameter structure that you access via the [IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters) method when the XAPO is bound to the audio graph.

**Note** **XAudio2CreateVolumeMeter** is an inline function in xaudio2fx.h that calls **CreateAudioVolumeMeter**:
``` syntax

XAUDIO2FX_STDAPI CreateAudioVolumeMeter(_Outptr_ IUnknown** ppApo);
__inline HRESULT XAudio2CreateVolumeMeter(_Outptr_ IUnknown** ppApo, UINT32 /*Flags*/ DEFAULT(0))
{
    return CreateAudioVolumeMeter(ppApo);
}

```

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters)

[XAUDIO2FX_VOLUMEMETER_LEVELS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_volumemeter_levels)

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)