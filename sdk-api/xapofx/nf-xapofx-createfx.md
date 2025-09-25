# CreateFX function

## Description

Creates an instance of the requested [XAPOFX](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview) effect.

## Parameters

### `clsid`

ID of the effect to create. Use the **__uuidof** on the effect class name to get the CLSID for an effect. For example, **__uuidof**(FXReverb) would provide the CLSID for the FXReverb effect. For a list of effects provided by XAPOFX, see [XAPOFX Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview). For an example of retrieving the CLSID for an effect, see [How to: Use XAPOFX in XAudio2](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-xapofx-in-xaudio2).

### `pEffect`

Receives a pointer to the created XAPO instance. If **CreateFX** fails, *pEffect*  is untouched.

### `pInitData` [optional]

Effect-specific initialization parameters. This is **NULL** if *InitDataByteSize* is zero.

### `InitDataByteSize` [optional]

Size of *pInitData* in bytes. This is zero if *pInitData* is **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The created XAPO will have a reference count of 1. Client code must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-release) after passing the XAPO to XAudio2 to allow XAudio2 to dispose of the XAPO when it is no longer needed. Use  [IXAudio2::CreateSourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsourcevoice) or [IXAudio2Voice::SetEffectChain](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectchain) to pass an XAPO to XAudio2.

**Note** The DirectX SDK version of this function doesn't have the *pInitData* or *InitDataByteSize* parameters as it only takes the first 2 parameters. To set initial parameters for the [XAPOFX](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview) effect that is created with the DirectX SDK version of this function, you must bind that effect to a voice and use [IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters).
For info about how to do this, see [How to: Use XAPOFX in XAudio2](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-xapofx-in-xaudio2).

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)