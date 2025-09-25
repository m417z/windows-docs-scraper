# IWMPEffects::GetCapabilities

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCapabilities** method gets the capabilities of the visualization.

## Parameters

### `pdwCapabilities` [out]

**DWORD** containing the capabilities.

The current values are as follows.

| Value | Description |
| --- | --- |
| **EFFECT_CANGOFULLSCREEN** = 0x00000001; | The visualization is capable of full-screen rendering. |
| **EFFECT_HASPROPERTYPAGE** = 0x00000002; | The visualization has a property page. |
| **EFFECT_VARIABLEFREQSTEP** = 0x00000004; | The visualization will use frequency data with variable size steps. If this bit is set, step size is based on the media sampling frequency divided by BUFFER_SIZE. If this bit is not set and media is played that was sampled at a low frequency, the upper cells will be empty. For example, if an 8KHz sampled file is played and this bit is not set, the upper half of the frequency array (from 8KHz to 22KHz) will be empty. If this bit is set and an 8Khz sampled file is played, the frequency array will range from 20Hz to 8KHz in BUFFER_SIZE steps. |
| **EFFECT_WINDOWED_ONLY** = 0x00000008 | The visualization only renders in windowed mode. |
| **EFFECT2_FULLSCREENEXCLUSIVE** = 0x00000010 | The visualization uses exclusive mode when rendering full-screen. The Player will not resize the window to fill the screen. The visualization must create a top level window and handle resolution switching. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

A default implementation of this method is not included in the visualization wizard.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)