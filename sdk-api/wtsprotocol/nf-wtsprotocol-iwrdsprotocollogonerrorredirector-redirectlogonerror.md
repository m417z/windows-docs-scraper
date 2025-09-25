# IWRdsProtocolLogonErrorRedirector::RedirectLogonError

## Description

Queries the protocol for the action to take in response to a logon error. The [RedirectStatus](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollogonerrorredirector-redirectstatus) method is called by the Remote Desktop Services service to query the protocol for the action to take in response to a logon error.

## Parameters

### `ntsStatus` [in]

An integer that contains information about the logon failure. This can be one of the following values.

#### STATUS_QUOTA_EXCEEDED

The memory quota is insufficient to allocate the output buffer returned by the authentication package.

#### STATUS_ACCOUNT_RESTRICTION

The user account and password are legitimate, but the user account has a restriction that prevents logon at this time. For more information, see the *ntsSubstatus* parameter.

#### STATUS_BAD_VALIDATION_CLASS

The authentication information provided is not recognized by the authentication package.

#### STATUS_LOGON_FAILURE

The logon attempt failed. The reason for the failure is not specified, but typical reasons include misspelled user names and misspelled passwords.

#### STATUS_NO_LOGON_SERVERS

No domain controllers are available to service the authentication request.

#### STATUS_NO_SUCH_PACKAGE

The specified authentication package is not recognized by the LSA.

### `ntsSubstatus` [in]

An integer that contains information about why a logon attempt failed. This value is set only if the account information of the user is valid and the logon is rejected. This can contain one of the following values.

#### STATUS_INVALID_LOGON_HOURS

The user account has time restrictions and cannot be used to log on at this time.

#### STATUS_INVALID_WORKSTATION

The user account has workstation restrictions and cannot be used to log on from the current workstation.

#### STATUS_PASSWORD_EXPIRED

The user account password has expired.

#### STATUS_ACCOUNT_DISABLED

The user account is currently disabled and cannot be used to log on.

### `pszCaption` [in]

A pointer to a string that contains the message box caption.

### `pszMessage` [in]

A pointer to a string that contains the message.

### `uType` [in]

An integer that contains the message box type. For more information, see the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function.

### `pResponse` [out]

A pointer to a [WRDS_LOGON_ERROR_REDIRECTOR_RESPONSE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_logon_error_redirector_response) enumeration that specifies to the Remote Desktop Services service the preferred response to the logon error.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollogonerrorredirector)