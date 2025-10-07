# WMDRM\_ENCRYPT\_SCATTER\_INFO structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_ENCRYPT\_SCATTER\_INFO** structure contains information needed to configure the [**IWMDRMEncryptScatter**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmencryptscatter) interface for use.

## Members

**dwStreamID**

Identifier of the stream to be encrypted.

**dwSampleProtectionVersion**

Sample protection version to be used to encode data from the specified stream.

**cbProtectionInfo**

Size of the **pbProtectionInfo** buffer in bytes.

**pbProtectionInfo**

Buffer containing additional protection information.

## Remarks

This structure is used by the [**IWMDRMEncryptScatter::InitEncryptScatter**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmencryptscatter-initencryptscatter) method.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

