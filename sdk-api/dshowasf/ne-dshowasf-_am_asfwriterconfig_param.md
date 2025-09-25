# _AM_ASFWRITERCONFIG_PARAM enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **_AM_ASFWRITERCONFIG_PARAM** DirectShow QASF enumeration type defines filter configuration parameters used in the [IConfigAsfWriter2::GetParam](https://learn.microsoft.com/windows/desktop/wmformat/iconfigasfwriter2-getparam) and [SetParam](https://learn.microsoft.com/windows/desktop/wmformat/iconfigasfwriter2-setparam) methods.

## Constants

### `AM_CONFIGASFWRITER_PARAM_AUTOINDEX:1`

Indicates whether the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/wmformat/wm-asf-writer-filter) should automatically create a temporal index after it has completed encoding a file. Set this parameter to **FALSE** if you want to create a frame-based index using the Windows Media Format SDK directly.

### `AM_CONFIGASFWRITER_PARAM_MULTIPASS`

Indicates whether the filter should operate in two-pass mode. See Remarks.

### `AM_CONFIGASFWRITER_PARAM_DONTCOMPRESS`

Indicates that the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/wmformat/wm-asf-writer-filter) will not attempt to compress the input streams. Use this flag to pack content that is not Windows Media–based into an ASF file.

## Remarks

In two-pass mode the filter makes two passes through the file. In the first pass, the filter examines each media stream in its entirety to determine the optimal encoding parameters for the file. The actual encoding is performed in the second pass. Therefore, to create an ASF file in two-pass mode, you must run the graph, wait for an **EC_PREPROCESS_COMPLETE** event, seek to the beginning of the source file, and then run the graph a second time.

**Important** To receive the **EC_PREPROCESS_COMPLETE** event you must use the DirectShow **GetEvent** method as demonstrated in the DSCopy sample. The DirectShow **WaitForCompletion** method will not receive this particular event.

## See also

[Configuring Profiles and Other File Properties (QASF)](https://learn.microsoft.com/windows/desktop/wmformat/configuring-profiles-and-other-file-properties--qasf)

[DirectShow QASF Reference](https://learn.microsoft.com/windows/desktop/wmformat/directshow-qasf-reference)

[IConfigAsfWriter2::GetParam](https://learn.microsoft.com/windows/desktop/wmformat/iconfigasfwriter2-getparam)

[IConfigAsfWriter2::SetParam](https://learn.microsoft.com/windows/desktop/wmformat/iconfigasfwriter2-setparam)