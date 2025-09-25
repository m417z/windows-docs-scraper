# DRM_VAL16 structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM_VAL16** structure is used by some DRM-related methods for passing 128-bit device identification values.

## Members

### `val`

Array of **BYTE** values that contains a 128-bit value. Data is stored with the high-order byte in the lowest address (big-endian).

## Remarks

This structure is used to store the device serial number for network devices, such as set-top boxes.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)