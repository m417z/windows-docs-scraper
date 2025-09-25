# WintrustAddActionID function

## Description

[The **WintrustAddActionID** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WintrustAddActionID** function adds a trust provider action to the user's system. This method should be called during the [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) implementation of the trust provider. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

This method should be called only by a trust provider.

## Parameters

### `pgActionID` [in]

A pointer to a **GUID** structure that identifies the action to add and the [trust provider](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that supports that action.

The WinTrust service is designed to work with trust providers implemented by third parties. Each trust provider provides its own unique set of action identifiers. For information about the action identifiers supported by a trust provider, see the documentation for that trust provider.

For example, Microsoft provides a Software Publisher Trust Provider that can establish the trustworthiness of software being downloaded from the Internet or some other public network. The Software Publisher Trust Provider supports the following action identifiers. These constants are defined in Softpub.h.

| Value | Meaning |
| --- | --- |
| **WINTRUST_ACTION_GENERIC_VERIFY** | Verify a certificate chain only. |
| **WINTRUST_ACTION_GENERIC_VERIFY_V2** | Verify a file or object using the Authenticode policy provider. |
| **HTTPSPROV_ACTION** | Verify an SSL/PCT connection through Internet Explorer. |

### `fdwFlags` [in]

a value that determines whether registry errors are reported by this function. If *fdwFlags* is zero and this function experiences a registry error, the registry error will not be propagated to the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If *fdwFlags* is WT_ADD_ACTION_ID_RET_RESULT_FLAG (0x1) and this function experiences a registry error, the registry error will be propagated to the **GetLastError** function.

### `psProvInfo` [in]

A pointer to the [CRYPT_REGISTER_ACTIONID](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_register_actionid) structure that defines the information for the trust provider.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure. For information about any registry errors that this function may encounter, see the description for *fdwFlags*.

## Remarks

To remove an action that has been added by this function, call the [WintrustRemoveActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustremoveactionid) function.

## See also

[WintrustRemoveActionID](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustremoveactionid)