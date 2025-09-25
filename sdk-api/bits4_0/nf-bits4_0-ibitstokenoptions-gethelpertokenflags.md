# IBitsTokenOptions::GetHelperTokenFlags

## Description

Returns the usage flags for a token that is associated with a BITS transfer job.

## Parameters

### `pFlags` [out]

Specifies the usage flag to return. This parameter must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| **BG_TOKEN_LOCAL_FILE**<br><br>0x0001 | If this flag is specified, the helper token is used<br><br>* To open the local file of an upload job<br>* To create or rename the temporary file of a download job<br>* To create or rename the reply file of an upload-reply job |
| **BG_TOKEN_NETWORK**<br><br>0x0002 | If this flag is specified, the helper token is used<br><br>* To open the remote file of a Server Message Block (SMB) upload or download job<br>* In response to an HTTP server or proxy challenge for implicit NTLM or Kerberos credentials<br><br>An application is required to call the [IBackgroundCopyJob2::SetCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials) method to allow the credentials to be sent over HTTP. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Older implementations effectively required that BITS users have administrator privileges in order to get helper token flags with this method. Starting with Windows 10, version 1607, non-administrator BITS users can use this method to get helper token usage flags on BITS jobs they own. This change enables non-administrator BITS users (such as background downloader services running under the [NetworkService account](https://learn.microsoft.com/windows/desktop/Services/networkservice-account)) to use helper tokens effectively.

Specifically, the implementation has been changed to allow users without administrator privileges to get helper token flags, as long as the SID of the caller's thread's token is the same as the SID of the job owner's user account during the [IBackgroundCopyJob::QueryInterface](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) call.

## See also

[IBitsTokenOptions](https://learn.microsoft.com/windows/desktop/api/bits4_0/nn-bits4_0-ibitstokenoptions)