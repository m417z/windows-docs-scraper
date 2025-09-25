# WMT_STATUS enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_STATUS** enumeration type defines a range of file status information. Members of **WMT_STATUS** are passed to the common callback function, [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus), so that the application can respond to the changing status of the objects being used.

## Constants

### `WMT_ERROR:0`

An error occurred.

### `WMT_OPENED:1`

A file was opened.

### `WMT_BUFFERING_START:2`

The reader object is beginning to buffer content.

### `WMT_BUFFERING_STOP:3`

The reader object has finished buffering content.

### `WMT_EOF:4`

The end of the file has been reached. Both this member and the next one, **WMT_END_OF_FILE**, have the value 4.

### `WMT_END_OF_FILE:4`

The end of the file has been reached. Both this member and the previous one, **WMT_EOF**, have the value 4.

### `WMT_END_OF_SEGMENT:5`

The end of a segment has been encountered.

### `WMT_END_OF_STREAMING:6`

The end of a server-side playlist has been reached.

### `WMT_LOCATING:7`

The reader object is locating requested data.

### `WMT_CONNECTING:8`

A reporting object is connecting to server.

### `WMT_NO_RIGHTS:9`

There is no [license](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) and the content is protected by version 1 digital rights management.

### `WMT_MISSING_CODEC:10`

The file loaded in the reader object contains compressed data for which no codec could be found. The *pValue* parameter in **OnStatus** contains a GUID. The first DWORD of this GUID contains the FOURCC or the format tag of the missing codec. The remaining bytes of the GUID can be ignored.

The *hr* parameter in **OnStatus** may equal S_OK, although a missing codec would normally be considered an error. Also, this event may be followed by WMT_STARTED with *hr* equal to S_OK, even if codecs are missing for every stream in the file. In that case, however, the application will not receive any decoded samples, and should stop the reader object.

### `WMT_STARTED:11`

A reporting object has begun operations.

### `WMT_STOPPED:12`

A reporting object has ceased operations.

### `WMT_CLOSED:13`

A file was closed.

### `WMT_STRIDING:14`

The reader object is playing content at above normal speed, or in reverse.

### `WMT_TIMER:15`

Timer event.

### `WMT_INDEX_PROGRESS:16`

Progress update from the indexer object.

### `WMT_SAVEAS_START:17`

The reader object has begun saving a file from a server.

### `WMT_SAVEAS_STOP:18`

The reader has stopped saving a file from a server.

### `WMT_NEW_SOURCEFLAGS:19`

The current file's header object contains certain attributes that are different from those of the previous file. This event is sent when playing a server-side playlist. Use the [IWMHeaderInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo) interface to query for any of the following attributes in a new file: [Stridable](https://learn.microsoft.com/windows/desktop/wmformat/stridable), [Broadcast](https://learn.microsoft.com/windows/desktop/wmformat/broadcast), [Seekable](https://learn.microsoft.com/windows/desktop/wmformat/seekable), and [HasImage](https://learn.microsoft.com/windows/desktop/wmformat/hasimage).

### `WMT_NEW_METADATA:20`

The current file's header object contains metadata attributes that are different from those of the previous file. This event is sent when playing a server-side playlist. Use the [IWMHeaderInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo) interface to query for any metadata attribute you are interested in.

### `WMT_BACKUPRESTORE_BEGIN:21`

A [license](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) backup or restore has started.

### `WMT_SOURCE_SWITCH:22`

The next source in the playlist was opened.

### `WMT_ACQUIRE_LICENSE:23`

The [license acquisition](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) process has completed. The *pValue* parameter in **OnStatus** contains a [WM_GET_LICENSE_DATA](https://learn.microsoft.com/windows/desktop/wmformat/wm-get-license-data) structure. The **hr** member of this structure indicates whether the license was successfully acquired.

### `WMT_INDIVIDUALIZE:24`

[Individualization](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) status message.

### `WMT_NEEDS_INDIVIDUALIZATION:25`

The file loaded in the reader object cannot be played without a security update.

### `WMT_NO_RIGHTS_EX:26`

There is no [license](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) and the content is protected by version 7 digital rights management.

### `WMT_BACKUPRESTORE_END:27`

A [license](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) backup or restore has finished.

### `WMT_BACKUPRESTORE_CONNECTING:28`

The backup restorer object is connecting to a server.

### `WMT_BACKUPRESTORE_DISCONNECTING:29`

The backup restorer object is disconnecting from a server.

### `WMT_ERROR_WITHURL:30`

Error relating to the URL.

### `WMT_RESTRICTED_LICENSE:31`

The backup restorer object cannot back up one or more [licenses](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) because the right has been disallowed by the content owner.

### `WMT_CLIENT_CONNECT:32`

Sent when a client (a playing application or server) connects to a writer network sink object. The *pValue* parameter of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback is set to a [WM_CLIENT_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_properties) structure. New applications should wait for **WMT_CLIENT_CONNECT_EX** instead.

### `WMT_CLIENT_DISCONNECT:33`

Sent when a client (a playing application or server) disconnects from a writer network sink object. The *pValue* parameter of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback is set to a [WM_CLIENT_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_properties) structure. The values in this structure are identical to those sent on connection. New applications should wait for **WMT_CLIENT_DISCONNECT_EX** instead.

### `WMT_NATIVE_OUTPUT_PROPS_CHANGED:34`

Change in output properties.

### `WMT_RECONNECT_START:35`

Start of automatic reconnection to a server.

### `WMT_RECONNECT_END:36`

End of automatic reconnection to a server.

### `WMT_CLIENT_CONNECT_EX:37`

Sent when a client (a playing application or server) connects to a writer network sink object. The *pValue* parameter of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback is set to a [WM_CLIENT_PROPERTIES_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_propertiesex) structure.

### `WMT_CLIENT_DISCONNECT_EX:38`

Sent when a client (a playing application or server) disconnects from a writer network sink object. The *pValue* parameter of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback is set to a [WM_CLIENT_PROPERTIES_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_propertiesex) structure. The client properties are identical to those sent on connection except for the **pwszDNSName** member, which may have changed.

### `WMT_SET_FEC_SPAN:39`

Change to the forward error correction span.

### `WMT_PREROLL_READY:40`

The reader is ready to begin buffering content.

### `WMT_PREROLL_COMPLETE:41`

The reader is finished buffering.

### `WMT_CLIENT_PROPERTIES:42`

Sent by a writer network sink when one or more properties of a connected client changes. The *pValue* parameter of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback is set to a [WM_CLIENT_PROPERTIES_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_propertiesex) structure. This usually means that a DNS name is present for a client for which none was available at connection.

### `WMT_LICENSEURL_SIGNATURE_STATE:43`

Sent before a **WMT_NO_RIGHTS** or **WMT_NO_RIGHTS_EX** status message. The *pValue* parameter is set to one of the [WMT_DRMLA_TRUST](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_drmla_trust) constants indicating whether the [license acquisition](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) URL is completely trusted.

### `WMT_INIT_PLAYLIST_BURN:44`

Sent when the [IWMReaderPlaylistBurn::InitPlaylistBurn](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderplaylistburn-initplaylistburn) method returns.

### `WMT_TRANSCRYPTOR_INIT:45`

Sent when the DRM transcryptor object is initialized with a file.

### `WMT_TRANSCRYPTOR_SEEKED:46`

Sent when the DRM transcryptor object seeks to a point in a file.

### `WMT_TRANSCRYPTOR_READ:47`

Sent when the DRM transcryptor object delivers Windows Media DRM 10 for Network Devices data from a DRM-protected file.

### `WMT_TRANSCRYPTOR_CLOSED:48`

Sent when the DRM transcryptor object is closed. After receiving this message, you can release the interface.

### `WMT_PROXIMITY_RESULT:49`

Sent when the proximity detection protocol has finished.

### `WMT_PROXIMITY_COMPLETED:50`

Sent when proximity detection thread has stopped running. The application must not release the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) interface until this message is received. Once launched, the thread runs for two minutes; there is no way to terminate the thread before two minutes have elapsed.

### `WMT_CONTENT_ENABLER:51`

Sent when a content enabler is required.

## Remarks

For more information on how this enumeration type is used, see the Remarks section for the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)