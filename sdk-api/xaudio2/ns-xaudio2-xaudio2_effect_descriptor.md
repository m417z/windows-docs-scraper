# XAUDIO2_EFFECT_DESCRIPTOR structure

## Description

Contains information about an [XAPO](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview) for use in an effect chain.

## Members

### `pEffect`

Pointer to the **IUnknown** interface of the [XAPO](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview) object.

### `InitialState`

TRUE if the effect should begin in the enabled state. Otherwise, FALSE.

### `OutputChannels`

Number of output channels the effect should produce.

## Remarks

XAPO instances are passed to XAudio2 as **IUnknown** interfaces and XAudio2 uses [IXAPO::QueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee418457(v=vs.85)) to acquire an [IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo) interface and to detect whether the XAPO implements the [IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters) interface.

For additional information on using XAPOs with XAudio2 see [How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain) and [How to: Use an XAPO in XAudio2](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-an-xapo-in-xaudio2).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio2 Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)

[XAudio2_Effect_Chain](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain)