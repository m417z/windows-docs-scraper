# WM_USER_TEXT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_USER_TEXT** structure is used as the data item for the [WM/Text](https://learn.microsoft.com/windows/desktop/wmformat/wm-text) complex metadata attribute.

## Members

### `pwszDescription`

Pointer to a wide-character null-terminated string containing the description of the text entry.

### `pwszText`

Pointer to a wide-character null-terminated string containing the text.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)