# KSTOPOLOGY\_CONNECTION structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This topic applies to Windows XP Service Pack 2 or later.

The **KSTOPOLOGY\_CONNECTION** structure describes a node connection within a kernel-streaming (KS) filter. A node can be connected to another node within the filter, or to a pin on the filter.

## Members

**FromNode**

Index of the upstream node in the connection. If the upstream connection is a pin, rather than a node, the value is KSFILTER\_NODE.

**FromNodePin**

If the value of the **FromNode** field is KSFILTER\_NODE, this field specifies the index of the upstream pin. Otherwise, this field is ignored.

**ToNode**

Index of the downstream node in the connection. If the downstream connection is a pin, rather than a node, the value is KSFILTER\_NODE.

**ToNodePin**

If the value of the **ToNode** field is KSFILTER\_NODE, this field specifies the index of the downstream pin. Otherwise, this field is ignored.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------|
| Header<br> | Ks.h |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

[**IKsTopologyInfo::get\_ConnectionInfo**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Vidcap/nf-vidcap-ikstopologyinfo-get_connectioninfo)

