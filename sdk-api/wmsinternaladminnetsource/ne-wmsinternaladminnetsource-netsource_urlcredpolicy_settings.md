# NETSOURCE_URLCREDPOLICY_SETTINGS enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **NETSOURCE_URLCREDPOLICY_SETTINGS** enumeration type is used for an output parameter of [IWMSInternalAdminNetSource2::GetCredentialsEx](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource2-getcredentialsex). It specifies possible security policy settings that can exist on a client computer. When you retrieve credentials, you must proceed as dictated by the user's security preferences. For more information, see **GetCredentialsEx**.

## Constants

### `NETSOURCE_URLCREDPOLICY_SETTING_SILENTLOGONOK:0`

Specifies that your application can log on to servers for which passwords are cached without informing the user.

### `NETSOURCE_URLCREDPOLICY_SETTING_MUSTPROMPTUSER:1`

Specifies that your application must notify the user when your application needs to log on to a server. You application can fill in the fields of a password dialog, but must get confirmation.

### `NETSOURCE_URLCREDPOLICY_SETTING_ANONYMOUSONLY:2`

Specifies that your application can never log on to network servers for the user. Your application can still navigate servers that do not require passwords.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)