# WMT_INDEXER_TYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_INDEXER_TYPE** enumeration type defines the types of indexing supported by the indexer.

## Constants

### `WMT_IT_PRESENTATION_TIME:0`

The indexer will construct an index using presentation times as indexes.

### `WMT_IT_FRAME_NUMBERS`

The indexer will construct an index using frame numbers as indexes.

### `WMT_IT_TIMECODE`

The indexer will construct an index using SMPTE time codes as indexes.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)