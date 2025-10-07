# DRM\_PLAYLIST\_CONTENT\_ID structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_PLAYLIST\_CONTENT\_ID** structure contains information about content that is to be copied to CD as part of a playlist burn.

## Members

**lpcwszV2Header**

DRM header. Use this member if the content is protected by Windows Media DRM version 2 or later.

**lpcszV1KID**

Key ID. Use this member if the content is protected by Windows Media DRM version 1.

**pbOtherData**

Buffer containing supplementary data.

**cbOtherData**

Size of the **pbOtherData** buffer in bytes.

**dwUniqueIDForSession**

Unique identifier for the content to be used in the current session.

**dwValidFields**

**DWORD** indicating the valid fields of this structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 11 SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/structures)

