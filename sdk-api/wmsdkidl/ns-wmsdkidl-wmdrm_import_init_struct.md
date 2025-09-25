# WMDRM_IMPORT_INIT_STRUCT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM_IMPORT_INIT_STRUCT** structure holds the encrypted session key and content key used in importing protected content.

## Members

### `dwVersion`

Version.

### `cbEncryptedSessionKeyMessage`

Size of the encrypted session key message in bytes.

### `pbEncryptedSessionKeyMessage`

Address of a buffer containing the encrypted session key message. This message is contained in a field of a [WMDRM_IMPORT_SESSION_KEY](https://learn.microsoft.com/windows/desktop/wmformat/wmdrm-import-session-key) structure. The message and its associated key data are both encrypted with the Windows Media DRM machine public key.

### `cbEncryptedKeyMessage`

Size of the encrypted key message in bytes.

### `pbEncryptedKeyMessage`

Address of a buffer containing the encrypted key message. This message is contained in a field of a [WMDRM_IMPORT_CONTENT_KEY](https://learn.microsoft.com/windows/desktop/wmformat/wmdrm-import-content-key) structure. The message and its associated key data are both encrypted with the Windows Media DRM machine public key.

## Remarks

This structure is used to initialize protected stream sample writing in a call to the [IWMDRMWriter3::SetProtectStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmwriter3-setprotectstreamsamples) method.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)