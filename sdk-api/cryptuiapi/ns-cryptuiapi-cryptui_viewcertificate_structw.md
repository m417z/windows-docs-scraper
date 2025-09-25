# CRYPTUI_VIEWCERTIFICATE_STRUCTW structure

## Description

The **CRYPTUI_VIEWCERTIFICATE_STRUCT** structure contains information about a certificate to view. This structure is used in the [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea) function.

## Members

### `dwSize`

The size, in bytes, of the **CRYPTUI_VIEWCERTIFICATE_STRUCT** structure.

### `hwndParent`

A handle to the window that is the parent of the dialog box produced by [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea).

### `dwFlags`

 This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_HIDE_HIERARCHYPAGE** | The **Certification Path** page is disabled. |
| **CRYPTUI_HIDE_DETAILPAGE** | The **Details** page is disabled. |
| **CRYPTUI_DISABLE_EDITPROPERTIES** | The user is not allowed to change the properties. |
| **CRYPTUI_ENABLE_EDITPROPERTIES** | The user is allowed to change the properties. |
| **CRYPTUI_DISABLE_ADDTOSTORE** | The **Install** button is disabled. |
| **CRYPTUI_ENABLE_ADDTOSTORE** | The **Install** button is enabled. |
| **CRYPTUI_ACCEPT_DECLINE_STYLE** | The pages or buttons that allow the user to accept or decline any decision are disabled. |
| **CRYPTUI_IGNORE_UNTRUSTED_ROOT** | An untrusted root error is ignored. |
| **CRYPTUI_DONT_OPEN_STORES** | Known trusted stores will not be used to build the chain. |
| **CRYPTUI_ONLY_OPEN_ROOT_STORE** | A known trusted root store will not be used to build the chain. |
| **CRYPTUI_WARN_UNTRUSTED_ROOT** | Use only when viewing certificates on remote computers. If this flag is used, the first element of **rghStores** must be the handle of the root store on the remote computer. |
| **CRYPTUI_ENABLE_REVOCATION_CHECKING** | Enable revocation checking with default behavior. The default behavior is to enable revocation checking of the entire certificate chain except the root certificate. Valid only if neither the **pCryptProviderData** nor the **hWVTStateData** union member is passed in. |
| **CRYPTUI_WARN_REMOTE_TRUST** | When building a certificate chain for a remote computer, warn that the chain may not be trusted on the remote computer. |
| **CRYPTUI_DISABLE_EXPORT** | If this flag is set, the **Copy to file** button will be disabled on the **Detail** page. |
| **CRYPTUI_ENABLE_REVOCATION_CHECK_END_CERT** | Enable revocation checking only on the leaf certificate in the certificate chain. Valid only if neither the **pCryptProviderData** nor the **hWVTStateData** union member is passed in. |
| **CRYPTUI_ENABLE_REVOCATION_CHECK_CHAIN** | Enable revocation checking on each certificate in the certificate chain. Valid only if neither the **pCryptProviderData** nor the **hWVTStateData** union member is passed in.<br><br>**Note** Because root certificates rarely contain information that allows revocation checking, it is expected that use of this option will usually result in failure of the [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea) function. The recommended option is to use CRYPTUI_ENABLE_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT. |
| **CRYPTUI_ENABLE_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT** | Enable revocation checking on each certificate in the certificate chain except for the root certificate. This is the recommended option to use for certificate revocation checking. Valid only if neither the **pCryptProviderData** nor the **hWVTStateData** union member is passed in.<br><br>**Note** This flag is equivalent to CRYPTUI_ENABLE_REVOCATION_CHECKING. |
| **CRYPTUI_DISABLE_HTMLLINK** | Disable the HTML Help button (**?**) in the **Certificate** dialog box. |
| **CRYPTUI_DISABLE_ISSUERSTATEMENT** | Disable the **Issuer Statement** button on the **General** tab of the **Certificate** dialog box. |
| **CRYPTUI_CACHE_ONLY_URL_RETRIEVAL** | Disable online revocation checking. Set this flag to ensure that the [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea) function uses the local cache to retrieve the certificate and does not attempt to retrieve the certificate from the network.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |

### `szTitle`

A pointer to a null-terminated string that contains the title for the window.

### `pCertContext`

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate context to display.

### `rgszPurposes`

An array of pointers to null-terminated strings that contain the purposes for which this certificate will be validated.

### `cPurposes`

The number of purposes in the **rgszPurposes** array.

### `pCryptProviderData`

If the [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function has already been called for the certificate and the [WTHelperProvDataFromStateData](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelperprovdatafromstatedata) function was also called, pass in a pointer to the state structure that was acquired from the call to **WTHelperProvDataFromStateData**. If **pCryptProviderData** is set, **fpCryptProviderDataTrustedUsage**, **idxSigner**, **idxCert**, and **fCounterSignature** must also be set.

### `hWVTStateData`

If [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) has already been called for the certificate and [WTHelperProvDataFromStateData](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelperprovdatafromstatedata) was not called, pass in the **hWVTStateData** member of the [WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data) structure. If **hWVTStateData** is set, **fpCryptProviderDataTrustedUsage**, **idxSigner**, **idxCert**, and **fCounterSignature** must also be set.

### `fpCryptProviderDataTrustedUsage`

If [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) was called, this is the result of whether the certificate was trusted.

### `idxSigner`

The index of the signer to view.

### `idxCert`

The index of the certificate that is being viewed within the signer chain. The certificate context of this cert must match **pCertContext**.

### `fCounterSigner`

**TRUE** if a countersignature is being viewed. If this is **TRUE**, **idxCounterSigner** must be valid.

### `idxCounterSigner`

The index of the countersigner to view.

### `cStores`

The number of other stores in the **rghStores** array of certificate stores to search when building and validating the certificate chain.

### `rghStores`

An array of **HCERTSTORE** handles to other certificate stores to search when building and validating the certificate chain.

### `cPropSheetPages`

The number of property pages to add to the dialog box.

### `rgPropSheetPages`

An array of property pages to add to the dialog box. Each page in this array will not receive the **lParam** in the [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure as the **lParam** in the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. It will instead receive a pointer to a [CRYPTUI_INITDIALOG_STRUCT](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cryptui_initdialog_struct) structure. It contains the **lParam** in **PROPSHEETPAGE** and the pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) for which the page is being displayed.

### `nStartPage`

The index of the initial page that will be displayed. If the highest bit (0x8000) is set, the index is assumed to index **rgPropSheetPages** (after the highest bit has been stripped off, for example, 0x8000 will indicate the first page in **rgPropSheetPages**). If the highest bit is zero, **nStartPage** will be the starting index of the default certificate dialog box property pages.

## See also

[CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea)

## Remarks

> [!NOTE]
> The cryptuiapi.h header defines CRYPTUI_VIEWCERTIFICATE_STRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).