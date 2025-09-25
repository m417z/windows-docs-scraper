# IBitsTokenOptions::SetHelperTokenFlags

## Description

Sets the usage flags for a token that is associated with a BITS transfer job.

## Parameters

### `UsageFlags`

Specifies the usage flag. This parameter must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| **BG_TOKEN_LOCAL_FILE**<br><br>0x0001 | If this flag is specified, the helper token is used<br><br>* To open the local file of an upload job<br>* To create or rename the temporary file of a download job<br>* To create or rename the reply file of an upload-reply job |
| **BG_TOKEN_NETWORK**<br><br>0x0002 | If this flag is specified, the helper token is used<br><br>* To open the remote file of a Server Message Block (SMB) upload or download job<br>* In response to an HTTP server or proxy challenge for implicit NTLM or Kerberos credentials<br><br>An application is required to call [IBackgroundCopyJob2::SetCredentials (..., NULL, NULL)](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials) to allow the credentials to be sent over HTTP. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The helper token usage flags specify which resources are to be accessed using the helper token’s security context. BITS will access all other resources using the job owner’s security context. For example, the client certificate is accessed by using the job owner identity.

If a client certificate is specified and the owner of the BITS job is not the LocalSystem account, setting the *UsageFlag* parameter to **BG_TOKEN_NETWORK** will cause the job to fail with the error code 0x80072f9a (**ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY**).

Older implementations effectively required that BITS users have administrator privileges in order to set helper token usage flags with this method. Starting with Windows 10, version 1607, non-administrator BITS users can use this method to set non-administrator helper token usage flags on BITS jobs they own. This change enables non-administrator BITS users (such as background downloader services running under the [NetworkService account](https://learn.microsoft.com/windows/desktop/Services/networkservice-account)) to use helper tokens effectively.

Specifically, the implementation has been changed to allow users without administrator privileges to set helper token usage flags, as long as the SID of the caller's thread's token is the same as the SID of the job owner's user account during the [IBackgroundCopyJob::QueryInterface](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) call, and the helper token that is currently set (if any) does not have the administrator SID (**DOMAIN_ALIAS_RID_ADMINS**) enabled.

## See also

[IBitsTokenOptions](https://learn.microsoft.com/windows/desktop/api/bits4_0/nn-bits4_0-ibitstokenoptions)