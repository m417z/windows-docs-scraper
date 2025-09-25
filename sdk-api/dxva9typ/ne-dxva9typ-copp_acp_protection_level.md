# COPP_ACP_Protection_Level enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the ACP protection level.

## Constants

### `COPP_ACP_Level0:0`

Level 0.

### `COPP_ACP_LevelMin`

Minimum ACP level. Equivalent to **COPP_ACP_Level0**.

### `COPP_ACP_Level1:1`

Level 1.

### `COPP_ACP_Level2:2`

Level 2.

### `COPP_ACP_Level3:3`

Level 3.

### `COPP_ACP_LevelMax`

Maximum ACP level. Equivalent to **COPP_ACP_Level3**.

### `COPP_ACP_ForceDWORD:0x7fffffff`

Reserved.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)