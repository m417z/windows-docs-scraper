# WMT_DRMLA_TRUST enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the trust state of a DRM license acquisition URL.

## Constants

### `WMT_DRMLA_UNTRUSTED:0`

Indicates that the validity of the license acquisition URL cannot be guaranteed because it is not signed. All protected content created prior to Windows Media 9 Series will cause this value to be returned.

### `WMT_DRMLA_TRUSTED`

Indicates that the license acquisition URL is the original one provided with the content.

### `WMT_DRMLA_TAMPERED`

Indicates that the license acquisition URL was originally signed and has been tampered with.

## Remarks

When a **WMT_LICENSEURL_SIGNATURE_STATE** message is received in the **OnStatus** callback method, pValue will be set to one of the **WMT_DRMLA_TRUST** constants, which indicate whether there is any problem with the digital signature applied to the license acquisition URL.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)