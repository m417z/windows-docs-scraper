# WMDRM\_IMPORT\_SESSION\_KEY structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_IMPORT\_SESSION\_KEY** structure holds the session key for importing protected content.

## Members

**dwKeyType**

Session key type. Set to WMDRM\_KEYTYPE\_RC4.

**cbKey**

Size of the session key, in bytes. This value can be as large as you need, given the limits of a single RSA OAEP operation over the entire message (this structure plus the session key).

**rgbKey**

Address of a buffer containing the session key. The buffer size must match the value of **cbKey**. The data in the buffer is a randomly generated key value.

## Remarks

This structure, including the buffer containing the session key, must be encrypted with the Windows Media DRM machine public key and included in the **pbEncryptedSessionKeyMessage** member of the [**WMDRM\_IMPORT\_INIT\_STRUCT**](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmdrm_import_init_struct) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 11 SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/structures)

