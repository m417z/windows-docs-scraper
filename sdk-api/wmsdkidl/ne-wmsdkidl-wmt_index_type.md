# WMT_INDEX_TYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_INDEX_TYPE** enumeration type defines the type of object that will be associated with an index. Because the time specified by an index will not usually correspond exactly with an object in the file, the indexer must associate the index with an object in the bit stream close to the specified time.

## Constants

### `WMT_IT_NEAREST_DATA_UNIT:1`

The index will associate indexes with the nearest data unit, or packet, in the Windows Media file.

### `WMT_IT_NEAREST_OBJECT`

The index will associate indexes with the nearest data object, or compressed sample, in the Windows Media file.

### `WMT_IT_NEAREST_CLEAN_POINT`

The index will associate indexes with the nearest [cleanpoint](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary), or video key frame, in the Windows Media file. This is the default index type.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)