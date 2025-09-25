# COPP_TVProtectionStandard enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines a list of TV protection standards
for Certified Output Protection Protocol (COPP).

## Constants

### `COPP_ProtectionStandard_Unknown:0x80000000`

None.

### `COPP_ProtectionStandard_None:0x00000000`

Unknown.

### `COPP_ProtectionStandard_IEC61880_525i:0x00000001`

IEC 61880, 525i.

### `COPP_ProtectionStandard_IEC61880_2_525i:0x00000002`

IEC 61880-2, 525i.

### `COPP_ProtectionStandard_IEC62375_625p:0x00000004`

IEC 62375, 625p.

### `COPP_ProtectionStandard_EIA608B_525:0x00000008`

EIA/CEA-608-B, 525i.

### `COPP_ProtectionStandard_EN300294_625i:0x00000010`

ETSI EN 300 294, 625i.

### `COPP_ProtectionStandard_CEA805A_TypeA_525p:0x00000020`

CEA-805-A Type A, 525p.

### `COPP_ProtectionStandard_CEA805A_TypeA_750p:0x00000040`

CEA-805-A Type A, 750p.

### `COPP_ProtectionStandard_CEA805A_TypeA_1125i:0x00000080`

CEA-805-A Type A, 1125i.

### `COPP_ProtectionStandard_CEA805A_TypeB_525p:0x00000100`

CEA-805-A Type B, 525p.

### `COPP_ProtectionStandard_CEA805A_TypeB_750p:0x00000200`

CEA-805-A Type B, 750p.

### `COPP_ProtectionStandard_CEA805A_TypeB_1125i:0x00000400`

CEA-805-A Type B, 1125i.

### `COPP_ProtectionStandard_ARIBTRB15_525i:0x00000800`

ARIB TR-B15, 525i.

### `COPP_ProtectionStandard_ARIBTRB15_525p:0x00001000`

ARIB TR-B15, 525p.

### `COPP_ProtectionStandard_ARIBTRB15_750p:0x00002000`

ARIB TR-B15, 750p.

### `COPP_ProtectionStandard_ARIBTRB15_1125i:0x00004000`

ARIB TR-B15, 1125i.

### `COPP_ProtectionStandard_Mask:0x80007FFF`

Reserved.

### `COPP_ProtectionStandard_Reserved:0x7FFF8000`

Reserved.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)