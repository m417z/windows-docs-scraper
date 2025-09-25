# IMSCEPSetup::SetAccountInformation

## Description

The **SetAccountInformation** method sets the user account information used by the IIS Network Device Enrollment Service (NDES) extension to perform enrollment on behalf of network devices.

## Parameters

### `bstrUserName` [in]

A string that contains the name of the user account to use with the IIS extension in the form [*DomainName*\]*UserName*.

### `bstrPassword` [in]

A string that contains the password for the user account.

## Remarks

The account must be a member of the **IIS_USRS** group on the computer.

If NDES is configured for an enterprise [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA), the account must have read permission on the **IPSecIntermediateOffline** template.

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)