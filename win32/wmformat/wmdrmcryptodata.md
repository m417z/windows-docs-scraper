# WMDRMCryptoData structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMCryptoData** structure contains information about the cryptographic algorithm used to encrypt and decrypt content.

## Members

**cryptoType**

Member of the [**DRM\_CRYPTO\_TYPE**](https://learn.microsoft.com/windows/win32/wmformat/drm-crypto-type) enumeration specifying the type of cryptographic algorithm.

**qwCounterID**

The high 64 bits of the 128-bit AES counter mode. This member is only used if the **cryptoType** member is set to **CRYPTO\_TYPE\_MCE**.

**qwOffset**

The low 64 bits of the 128-bit AES counter mode. This member is only used if the **cryptoType** member is set to **CRYPTO\_TYPE\_MCE**.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

