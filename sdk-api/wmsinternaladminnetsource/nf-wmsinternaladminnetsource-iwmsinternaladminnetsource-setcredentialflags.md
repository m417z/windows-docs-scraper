# IWMSInternalAdminNetSource::SetCredentialFlags

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCredentialFlags** method is used to set the user preference for automatic password caching. When your application prompts the user for a password, you can include a checkbox on the dialog box that the user can select to always have passwords saved. You can then set a flag to maintain that preference.

## Parameters

### `dwFlags` [in]

**DWORD** containing the credential flags. At this time, the only supported flag is 0x1, which signifies that the user has stated a preference that passwords should be saved automatically.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMSInternalAdminNetSource Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource)

[IWMSInternalAdminNetSource::GetCredentialFlags](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource-getcredentialflags)

[IWMSInternalAdminNetSource::SetCredentials](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource-setcredentials)