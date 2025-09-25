# WintrustRemoveActionID function

## Description

[The **WintrustRemoveActionID** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WintrustRemoveActionID** function removes an action added by the [WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid) function. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `pgActionID` [in]

A pointer to a **GUID** structure that identifies the action to remove and the [trust provider](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that supports that action.

The WinTrust service is designed to work with trust providers implemented by third parties. Each trust provider provides its own unique set of action identifiers. For information about the action identifiers supported by a trust provider, see the documentation for that trust provider.

For example, Microsoft provides a Software Publisher Trust Provider that can establish the trustworthiness of software being downloaded from the Internet or some other public network. The Software Publisher Trust Provider supports the following action identifiers. These constants are defined in Softpub.h.

| Value | Meaning |
| --- | --- |
| **WINTRUST_ACTION_GENERIC_VERIFY** | Verify a certificate chain only. |
| **WINTRUST_ACTION_GENERIC_VERIFY_V2** | Verify a file or object using the Authenticode policy provider. |
| **HTTPSPROV_ACTION** | Verify an SSL/PCT connection through Internet Explorer. |

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails.

## See also

[WintrustAddActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustaddactionid)