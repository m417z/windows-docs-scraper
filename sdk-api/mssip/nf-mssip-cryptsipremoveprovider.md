# CryptSIPRemoveProvider function

## Description

The **CryptSIPRemoveProvider** function removes registry details of a Subject Interface Package (SIP) DLL file added by a previous call to the [CryptSIPAddProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipaddprovider) function.

## Parameters

### `pgProv` [in]

A pointer to the GUID that identifies the SIP DLL to remove.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure.

## Remarks

Typically you call this function to unregister an in-process COM server. The **CryptSIPRemoveProvider** function removes the appropriate Registry entries for the SIP provider functions.

## See also

[CryptSIPAddProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipaddprovider)