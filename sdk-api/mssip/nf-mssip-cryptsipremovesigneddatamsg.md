# CryptSIPRemoveSignedDataMsg function

## Description

The **CryptSIPRemoveSignedDataMsg** function removes a specified [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) signature.

## Parameters

### `pSubjectInfo` [in]

A pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that contains information about the message subject.

### `dwIndex` [in]

This parameter is reserved and should be set to zero.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CryptSIPGetSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetsigneddatamsg)

[CryptSIPPutSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipputsigneddatamsg)