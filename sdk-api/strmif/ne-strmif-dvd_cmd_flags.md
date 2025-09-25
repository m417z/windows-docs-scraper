# DVD_CMD_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines flags that control how the [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter handles command synchronization.

## Constants

### `DVD_CMD_FLAG_None:0`

The DVD Navigator will not flush its buffers when it issues the command, will not send any events, and will not to block the thread of execution on any method call.

### `DVD_CMD_FLAG_Flush:0x1`

The DVD Navigator will flush all of its buffered video data before issuing the command. This can cause the DVD Navigator to discard approximately two seconds of video, which will decrease the response time but cause a gap in the playback data.

### `DVD_CMD_FLAG_SendEvents:0x2`

The DVD Navigator will send an [EC_DVD_CMD_START](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-cmd-start) event when the command begins, and an [EC_DVD_CMD_END](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-cmd-end) event when the command ends. The event parameters contain the status code of the operation.

### `DVD_CMD_FLAG_Block:0x4`

The DVD Navigator blocks until the command completes or is canceled.

### `DVD_CMD_FLAG_StartWhenRendered:0x8`

Currently not used.

### `DVD_CMD_FLAG_EndAfterRendered:0x10`

The DVD Navigator will block until the specified action is actually rendered. This flag can be used with the following methods:

* [IDvdControl2::PlayChaptersAutoStop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playchaptersautostop)
* [IDvdControl2::PlayPeriodInTitleAutoStop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playperiodintitleautostop)
* [IDvdControl2::SelectSubpictureStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectsubpicturestream)
* [IDvdControl2::SetSubpictureState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setsubpicturestate)

For example, when used with [PlayChaptersAutoStop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playchaptersautostop), this flag causes the DVD Navigator to block until the specified chapters have all played. When used with [SelectSubpictureStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectsubpicturestream), the flag causes the DVD Navigator to block until the new subpicture is rendered.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands)