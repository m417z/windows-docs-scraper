# WMDRM\_ENCRYPT\_SCATTER\_BLOCK structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_ENCRYPT\_SCATTER\_BLOCK** structure contains a block of data to be encrypted.

## Members

**dwStreamID**

Identifier of the stream to which the data block belongs.

**cbBlock**

Size of block in bytes.

**pbBlock**

Pointer to a buffer containing the data block.

## Remarks

This structure is used by the [**IWMDRMEncryptScatter::EncryptScatter**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmencryptscatter-encryptscatter) method to identify blocks of data to encrypt.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

