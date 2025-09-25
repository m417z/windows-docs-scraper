# WMT_WEBSTREAM_SAMPLE_HEADER structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_WEBSTREAM_SAMPLE_HEADER** structure is used as a variable-sized header for each Web stream sample.

## Members

### `cbLength`

**WORD** containing the size of **wszURL** in wide characters.

### `wPart`

**WORD** containing the zero-based part number to which the sample applies. When the last part is received, **wPart** equals **cTotalParts**– 1.

### `cTotalParts`

**WORD** containing the total number of parts in the Web stream.

### `wSampleType`

**WORD** containing the type of Web stream, either WEBSTREAM_SAMPLE_TYPE_FILE (0x1) or WEBSTREAM_SAMPLE_TYPE_RENDER (0x2). See Remarks.

### `wszURL`

Wide-character null-terminated string specifying the local URL.

## Remarks

In a Web stream, each sample begins with this structure. The application is responsible for determining the size of the structure for each sample delivered. The size depends on the length of the **wszURL** member, as reported in the **cbLength** member.

If **wSampleType** is WEBSTREAM_SAMPLE_TYPE_FILE, the sample contains data immediately following the header that should be cached for later rendering. If the type is WEBSTREAM_SAMPLE_TYPE_RENDER, the sample contains no data. The application should cause the file named in the **wszURL** member to be immediately rendered on the display.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)