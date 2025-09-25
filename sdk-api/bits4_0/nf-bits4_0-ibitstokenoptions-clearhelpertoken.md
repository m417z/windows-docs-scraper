# IBitsTokenOptions::ClearHelperToken

## Description

Discards the helper token, and does not change the usage flags.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Older implementations effectively required that BITS users have administrator privileges in order to clear a helper token with this method. Starting with Windows 10, version 1607, non-administrator BITS users can use this method to clear helper tokens on BITS jobs they own. This change enables non-administrator BITS users (such as background downloader services running under the [NetworkService account](https://learn.microsoft.com/windows/desktop/Services/networkservice-account)) to use helper tokens effectively.

Specifically, the implementation has been changed to allow users without administrator privileges to clear a helper token, as long as the SID of the caller's thread's token is the same as the SID of the job owner's user account during the [IBackgroundCopyJob::QueryInterface](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) call.

## See also

[IBitsTokenOptions](https://learn.microsoft.com/windows/desktop/api/bits4_0/nn-bits4_0-ibitstokenoptions)