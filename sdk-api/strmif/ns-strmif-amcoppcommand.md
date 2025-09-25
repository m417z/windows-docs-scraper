# AMCOPPCommand structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The AMCOPPCommand structure contains a Certified Output Protection Protocol (COPP) command.

## Members

### `macKDI`

Message Authentication Code (MAC) of the command data. Use AES-based one-key CBC MAC (OMAC) to calculate this value.

### `guidCommandID`

GUID that specifies the command.

### `dwSequence`

Sequence number. The application must keep a running count of the COPP commands issued. For each command, increment the sequence number by one.

### `cbSizeData`

Number of bytes of valid data in the **CommandData** member.

### `CommandData`

Data for the command. The meaning of the data depends on the command.

## Remarks

The following COPP commands are defined.

| **GUID** | Description |
| --- | --- |
| DXVA_COPPSetProtectionLevel | Sets a specified protection type to a specified protection level. |

For more information, see the Windows DDK documentation.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)