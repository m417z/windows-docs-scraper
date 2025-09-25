# CryptSIPAddProvider function

## Description

The **CryptSIPAddProvider** function registers functions that are exported by a given DLL file that implements a Subject Interface Package (SIP).

## Parameters

### `psNewProv` [in]

A pointer to a [SIP_ADD_NEWPROVIDER](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_add_newprovider) structure that specifies the DLL file and function names to register.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure.

## Remarks

Typically, you call this function as part of an in-process COM server registration. The **CryptSIPAddProvider** function persists the appropriate Registry entries for the SIP provider functions.

When you have finished using the added SIP provider, remove it by calling the [CryptSIPRemoveProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremoveprovider) function.

## See also

[CryptSIPRemoveProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremoveprovider)