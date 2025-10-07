# WMDRM\_IMPORT\_CONTENT\_KEY structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_IMPORT\_CONTENT\_KEY** structure stores the content key used in importing protected content.

## Members

**dwVersion**

Version.

**cbStructSize**

Size of structure in bytes.

**dwIVKeyType**

Initialization vector key type. Set to WMDRM\_KEYTYPE\_RC4.

**cbIVKey**

Size of the initialization vector key in bytes.

**dwContentKeyType**

Content key type. Set to WMDRM\_KEYTYPE\_COCKTAIL.

**cbContentKey**

Size of the content key in bytes.

**rgbKeyData**

Address of a buffer containing the content key. The buffer size must match the value of **cbContentKey**. This key should match the key imported from the XMR license message.

## Remarks

This structure, including the buffer containing the session key, must be encrypted with the session key and included in the **pbEncryptedKeyMessage** member of the [**WMDRM\_IMPORT\_INIT\_STRUCT**](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmdrm_import_init_struct) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 11 SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/structures)

