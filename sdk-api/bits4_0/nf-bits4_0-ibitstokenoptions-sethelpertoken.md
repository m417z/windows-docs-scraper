# IBitsTokenOptions::SetHelperToken

## Description

Sets the helper token to impersonate the token of the COM client. Because an application sets the token through COM impersonation, the token is not persistent and is valid only for the lifetime of a session. When the BITS service receives a log-off notification, the BITS service discards any helper tokens that are associated with the transfer job.

## Return value

The following value might be returned:

| Return code/value | Description |
| --- | --- |
| **CO_E_FAILEDTOIMPERSONATE**<br><br>0x80010123 | COM settings on the client do not allow impersonate-level access to the client token. |
| **E_ACCESSDENIED**<br><br>0x80070005 | * In versions prior to Windows 10, version 1607, the job is not owned by an administrator. In those versions of Windows, only administrator-owned jobs may set helper tokens.<br>* In Windows 10, version 1607 and newer versions, this error indicates that the helper token has administrator privileges, but the caller does not have administrator privileges. |

## Remarks

The helper token does not need to represent an administrator.

The impersonation level for the proxy blanket must be set to either **RPC_C_IMP_LEVEL_IMPERSONATE** or **RPC_C_IMP_LEVEL_DELEGATE**. For more information, see [Security Blanket Negotiation](https://learn.microsoft.com/windows/win32/com/security-blanket-negotiation).

The cloaking flag should be set to **EOAC_DYNAMIC_CLOAKING**, which enables the COM server to use the thread token as the client's identity. For more information, see [Cloaking](https://learn.microsoft.com/windows/win32/com/cloaking) and [EOLE_AUTHENTICATION_CAPABILITIES Enumeration](https://learn.microsoft.com/windows/win32/api/objidlbase/ne-objidlbase-eole_authentication_capabilities).

Older implementations effectively required that BITS users have administrator privileges in order to set helper tokens. Starting with Windows 10, version 1607, non-administrator BITS users can use **IBitsTokenOptions::SetHelperToken** to set non-administrator helper tokens on BITS jobs they own. This change enables non-administrator BITS users (such as background downloader services running under the [NetworkService account](https://learn.microsoft.com/windows/desktop/Services/networkservice-account)) to set helper tokens.

Specifically, the implementation has been changed to allow users without administrator privileges to set helper tokens, as long as the SID of the caller's thread's token is the same as the SID of the job owner's user account during the [IBackgroundCopyJob::QueryInterface](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) call, and the helper token being set does not have the administrator SID (**DOMAIN_ALIAS_RID_ADMINS**) enabled.

## See also

[IBitsTokenOptions](https://learn.microsoft.com/windows/desktop/api/bits4_0/nn-bits4_0-ibitstokenoptions)