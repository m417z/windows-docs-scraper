# DXVA_COPPSetProtectionLevelCmdData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains data for the Set Protection Level command in Certified Output Protection Protocol (COPP).

## Members

### `ProtType`

Identifies the protection mechanism. See [COPP Protection Type Flags](https://learn.microsoft.com/windows/desktop/DirectShow/copp-protection-type-flags).

### `ProtLevel`

Specifies the protection level. The meaning of this value depends on the protection mechanism that is queried. For each protection mechanism, the value of the `ProtLevel` member is a flag from a different enumeration, as shown in the following table.

| Protection mechanism | Enumeration |
| --- | --- |
| ACP | [COPP_ACP_Protection_Level](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_acp_protection_level) |
| CGMS-A | [COPP_CGMSA_Protection_Level](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_cgmsa_protection_level) |
| HDCP | [COPP_HDCP_Protection_Level](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_hdcp_protection_level) |

### `ExtendedInfoChangeMask`

Reserved. Must be zero.

### `ExtendedInfoData`

Reserved. Must be zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)