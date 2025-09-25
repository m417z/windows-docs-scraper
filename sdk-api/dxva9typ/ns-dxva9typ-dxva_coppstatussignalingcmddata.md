# DXVA_COPPStatusSignalingCmdData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains the result from a Signaling query in Certified Output Protection Protocol (COPP).

## Members

### `rApp`

A 128-bit random number that was passed by the application in the **AMCOPPStatusInput** structure.

### `dwFlags`

Status flag. See [COPP_StatusFlags](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_statusflags).

### `AvailableTVProtectionStandards`

Bitwise **OR** of flags from the [COPP_TVProtectionStandard](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_tvprotectionstandard) enumeration. The driver should return flags for all of the protection standards and resolutions that it supports.

### `ActiveTVProtectionStandard`

Member of the [COPP_TVProtectionStandard](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_tvprotectionstandard) enumeration, indicating the protection standard that is currently active.

### `TVType`

Reserved.

### `AspectRatioValidMask1`

Bit mask indicating which bits of **AspectRatioData1** are valid.

### `AspectRatioData1`

Specifies the current aspect ratio value. For EN 300 294, the value is a member of the [COPP_ImageAspectRatio_EN300294](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_imageaspectratio_en300294) enumeration.

### `AspectRatioValidMask2`

Bit mask indicating which bits of **AspectRatioData2** are valid.

### `AspectRatioData2`

Additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard. This field may be used to convey End and Q0 bits for EIA-608-B, or the active format description for CEA-805-A.

### `AspectRatioValidMask3`

Bit mask indicating which bits of **AspectRatioData3** are valid.

### `AspectRatioData3`

Additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard.

### `ExtendedInfoValidMask`

Array of bit masks indicating which bits in **ExtendedInfoData** are valid.

### `ExtendedInfoData`

Additional signaling elements. This array is currently not used.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)