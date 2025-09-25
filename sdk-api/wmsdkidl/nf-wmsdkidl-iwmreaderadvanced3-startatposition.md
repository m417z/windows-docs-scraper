# IWMReaderAdvanced3::StartAtPosition

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **StartAtPosition** method enables you to specify a starting position for a file using one of several offset formats. This method is very similar to [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start), except that the starting position and duration can be given for time, video frame number, SMPTE time code, or playlist position. If you only need to seek on presentation time, use **Start**.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which *pvOffsetStart* and *pvDuration* apply. Passing zero signifies that the offset start and duration apply for all streams in the file. If you pass zero, the only valid values for *dwOffsetFormat* are WMT_OFFSET_FORMAT_100NS and WMT_OFFSET_FORMAT_PLAYLIST_OFFSET.

### `pvOffsetStart` [in]

Void pointer to the address containing the offset start. The unit of measurement for the offset is determined by *dwOffsetFormat*. The unit of measurement also dictates the size of the variable pointed to. The possible variable types are listed according to offset format in the following table.

| Offset format | *pvOffsetStart* data type |
| --- | --- |
| WMT_OFFSET_FORMAT_100NS | **QWORD** |
| WMT_OFFSET_FORMAT_FRAME_NUMBERS | **QWORD** |
| WMT_OFFSET_FORMAT_PLAYLIST_OFFSET | **LONG** |
| WMT_OFFSET_FORMAT_TIMECODE | [WMT_TIMECODE_EXTENSION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_timecode_extension_data) |
| WMT_OFFSET_FORMAT_APPROXIMATE | **QWORD** |

### `pvDuration` [in]

Void pointer to the address containing the duration of playback. If zero is passed, playback will continue until the end of the file. The unit of measurement for the duration is determined by *dwOffsetFormat*. The unit of measurement also dictates the size of the variable pointed to. The possible variable types are listed according to offset format in the following table.

| Offset format | *pvDuration* data type |
| --- | --- |
| WMT_OFFSET_FORMAT_100NS | **QWORD** |
| WMT_OFFSET_FORMAT_FRAME_NUMBERS | **QWORD** |
| WMT_OFFSET_FORMAT_PLAYLIST_OFFSET | **QWORD** |
| WMT_OFFSET_FORMAT_TIMECODE | [WMT_TIMECODE_EXTENSION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_timecode_extension_data) |
| WMT_OFFSET_FORMAT_APPROXIMATE | **QWORD** |

### `dwOffsetFormat` [in]

**DWORD** containing one member of the [WMT_OFFSET_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_offset_format) enumeration type. Valid values and their meanings are as follows.

| Value | Description |
| --- | --- |
| WMT_OFFSET_FORMAT_100NS | The offset and duration are specified in 100-nanosecond units. This is the same offset format that is supported by the **IWMReader::Start** method. |
| WMT_OFFSET_FORMAT_FRAME_NUMBERS | The offset is specified by the video frame number at which to start playback. The duration is a number of video frames. |
| WMT_OFFSET_FORMAT_PLAYLIST_OFFSET | The offset is specified by an offset into a playlist. The duration is specified in 100-nanosecond units. |
| WMT_OFFSET_FORMAT_TIMECODE | The offset is specified by a SMPTE time code value. The duration is not a count, but another SMPTE time code value. |
| WMT_OFFSET_FORMAT_APPROXIMATE | The offset and duration are specified in 100-nanosecond units. When this format is used, playback begins with the closest clean point prior to the time provided. This format is intended to decrease seeking time when the exact sample is not required, such as in a player application's seek bar. |

### `fRate` [in]

Floating point number indicating playback rate. Normal-speed playback is 1.0; higher numbers cause faster playback, and lower numbers cause slower playback. Numbers less than zero indicate reverse rate (rewinding). The valid range is 1.0 through 10.0, and -1.0 through -10.0.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is passed back to the application on calls to [IWMReaderCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | *dwOffsetFormat* is WMT_OFFSET_FORMAT_FRAME_NUMBERS and *wStreamNum* is zero.<br><br>OR<br><br>*pvOffsetStart* is **NULL**, signifying a resume, and the reader is in stop mode. You cannot resume playback when the player has been stopped.<br><br>OR<br><br>*pvOffsetStart* is **NULL**, signifying a resume, and *pvDuration* is not **NULL**. You cannot specify a duration for a resume.<br><br>OR<br><br>No file is open in the reader.<br><br>OR<br><br>*fRate* is out of bounds.<br><br>OR<br><br>The reader receiving broadcast streams. You cannot seek from a broadcasting source.<br><br>OR<br><br>*fRate* is negative, indicating a rewind, and the duration would rewind to before the beginning of the file.<br><br>OR<br><br>*dwOffsetFormat* is WMT_OFFSET_FORMAT_FRAME_NUMBERS and the file is not indexed and/or is not indexed by frame. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for a message structure required internally. |

## Remarks

Frame-based access is available only for local files. You cannot use **StartAtPosition** to specify starting frame numbers for streamed content, even if the file is indexed by frame.

You can pass **NULL** for *pvOffsetStart* if you are making a call to resume paused playback. In this case you must also pass **NULL** for *pvDuration*.

If an invalid duration is specified, **StartAtPosition** will not fail. As many samples as possible will be delivered.

## See also

[IWMReaderAdvanced3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced3)