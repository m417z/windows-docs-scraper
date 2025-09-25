# DXVA_COPPSetSignalingCmdData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains information for the Set Signal command in Certified Output Protection Protocol (COPP).

This command causes the driver to insert Wide Screen Signalling (WSS) codes or other data packets in the television signal, as required by some Analog Copy Protection (ACP) and Copy Generation Management System — Analog (CGMS-A) specifications. For example:

* ETSI EN 300 294 (625i PAL): Data packets are inserted into line 23 of the signal.
* CEA-608-B (NTSC): Data packets are inserted into line 21 of the vertical blanking interval (VBI).

## Members

### `ActiveTVProtectionStandard`

Specifies the protection standard and format that is current active. The value is a member of the [COPP_TVProtectionStandard](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_tvprotectionstandard) enumeration.

### `AspectRatioChangeMask1`

Bit mask indicating which bits from **AspectRatioData1** to set in the signal.

### `AspectRatioData1`

Specifies the aspect ratio value to be set for the current protection standard. For EN 300 294, use the [COPP_ImageAspectRatio_EN300294](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_imageaspectratio_en300294) enumeration.

### `AspectRatioChangeMask2`

Bit mask indicating which bits from **AspectRatioData2** to set in the signal.

### `AspectRatioData2`

An additional data element related to aspect ratio. The presence and meaning of this data depends on the protection standard. This field can be used to convey End and Q0 bits for EIA-608-B, or the active format description for CEA-805-A.

### `AspectRatioChangeMask3`

Bit mask indicating which bits from **AspectRatioData3** to set in the signal.

### `AspectRatioData3`

An additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard.

### `ExtendedInfoChangeMask`

Array of bit masks indicating which bits in **ExtendedInfoData** to change. This array is currently not used. Set each member to zero.

### `ExtendedInfoData`

Additional signaling elements to be set. This array is currently not used.
Set each member to zero.

### `Reserved`

Reserved. Set to zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)