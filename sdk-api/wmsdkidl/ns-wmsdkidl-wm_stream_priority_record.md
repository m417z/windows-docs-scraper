# WM_STREAM_PRIORITY_RECORD structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_STREAM_PRIORITY_RECORD** structure contains a stream number and specifies whether delivery of that stream is mandatory.

## Members

### `wStreamNumber`

**WORD** containing the stream number.

### `fMandatory`

Flag indicating whether the listed stream is mandatory. Mandatory streams will not be dropped regardless of their position in the priority list.

## Remarks

**WM_STREAM_PRIORITY_RECORD** is used in an array by the **IWMStreamPrioritization** interface. Each member of the array specifies a stream; the lower the element number in the array, the higher the priority of the stream.

## See also

[IWMStreamPrioritization Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)