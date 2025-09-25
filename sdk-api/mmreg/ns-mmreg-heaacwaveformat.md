# HEAACWAVEFORMAT structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains format data for an AAC or HE-AAC stream that includes AudioSpecificConfig() data.

## Members

### `wfInfo`

A [HEAACWAVEINFO](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-heaacwaveinfo) structure.

### `pbAudioSpecificConfig`

A byte array that contains the value of AudioSpecificConfig(), as defined by ISO/IEC 14496-3. The array might be larger than the size given in the structure declaration. Use the value of **wfInfo.wfx.cbSize** to determine the size.

## Remarks

Use this structure to access the AudioSpecificConfig() data that follows an [HEAACWAVEINFO](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-heaacwaveinfo) structure. This data is present only when the **wStructType** member of the **HEAACWAVEFORMAT** structure is zero.