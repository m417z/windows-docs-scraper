# WMCreateSecureChannel function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Creates an object that implements [IWMSecureChannel](https://learn.microsoft.com/windows/desktop/api/wmsecure/nn-wmsecure-iwmsecurechannel).

## Parameters

### `ppChannel`

Address of a pointer to the [IWMSecureChannel](https://learn.microsoft.com/windows/desktop/api/wmsecure/nn-wmsecure-iwmsecurechannel) interface of the newly created secure channel object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWMSecureChannel](https://learn.microsoft.com/windows/desktop/api/wmsecure/nn-wmsecure-iwmsecurechannel)