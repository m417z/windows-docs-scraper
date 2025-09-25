# CERT_SELECT_STRUCT_W structure

## Description

The **CERT_SELECT_STRUCT** structure
contains criteria upon which to select certificates that are presented in a certificate selection
dialog box. This structure is used in the
[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea)
function.

## Members

### `dwSize`

The size, in bytes, of this structure.

### `hwndParent`

A handle to the parent window of any dialog boxes that
[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) generates.

### `hInstance`

A handle to the module whose executable file contains the dialog box template.

### `pTemplateName`

If the **CSS_ENABLETEMPLATE** flag is set in the **dwFlags**
member, set **pTemplateName** to a pointer to a global memory object that contains the
template that [DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)
uses to create the dialog box. A dialog box template consists of a header that describes the dialog box. The
header is followed by one or more additional blocks of data that describe each of the controls in the dialog
box. The template can use either the standard format or the extended format.

If the **CSS_ENABLETEMPLATEHANDLE** flag is set in **dwFlags**,
**pTemplateName** specifies the dialog box template.
**pTemplateName** is either the pointer to a null-terminated character string that
specifies the name of the dialog box template or an integer value that specifies the resource identifier of the
dialog box template. If the specifies a resource identifier, its high-order word must be zero and its
low-order word must contain the identifier. One way to create this integer value is to use the
[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro.

### `dwFlags`

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CSS_HIDE_PROPERTIES** | Hide the **Properties** button. |
| **CSS_ENABLEHOOK** | Pass a hook procedure in **pfnHook**. |
| **CSS_ALLOWMULTISELECT** | Enable multi-selection of certificates. This option is not currently supported and is ignored. |
| **CSS_SHOW_HELP** | Show the **Help** button. |
| **CSS_ENABLETEMPLATE** | Cause [CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function to call the [DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama) function to create a dialog box. For more information, see **pTemplateName**. |
| **CSS_ENABLETEMPLATEHANDLE** | Cause the [CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function to call the [DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama) function to create a dialog box. For more information, see **pTemplateName**. |

### `szTitle`

A pointer to a string that contains the text for the title of the dialog box.

### `cCertStore`

The number of elements in **arrayCertStore** array.

### `arrayCertStore`

A pointer to the array of certificate stores that the dialog box enumerates and displays the certificates
from. The **cCertStore** member contains the number of elements in this array.

### `szPurposeOid`

A pointer to a string representation of an object identifier (OID) for an enhanced key usage (EKU). If an
OID is provided, only certificates that include this EKU will be displayed.

### `cCertContext`

The number of elements in the **arrayCertContext** array. After the
[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function returns,
this member contains the number of certificates that were selected by the user. Currently, only one certificate
can be selected by the user.

### `arrayCertContext`

A pointer to an array of [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)
structures. The **cCertContext** member specifies the number of elements in this array.
This array must contain at least one element.

The certificates represented by these structures are selected when the dialog box displayed by the
[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function is
initially displayed. Currently, only the first certificate in this array is used. The first certificate in this
array will be released with the
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function
if the **CertSelectCertificate** function is
successful. If the first element in this array is **NULL**, no certificates are initially
selected in the dialog box.

After the [CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function
returns, this array contains the certificates that were selected by the user. Currently, only one certificate
can be selected by the user.

### `lCustData`

A pointer to an array of byte values that hold custom data that is passed through to the filter procedure
referenced by **pfnFilter**. This custom data is not used by the
[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function.

### `pfnHook`

A [PFNCMHOOKPROC](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nc-cryptdlg-pfncmhookproc) function pointer to the Hook
callback function. This function is called before messages are processed by the dialog box. For more
information, see [Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks).

### `pfnFilter`

A [PFNCMFILTERPROC](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nc-cryptdlg-pfncmfilterproc) function pointer to the
filter callback function. This is called to determine which certificates will be displayed by the dialog
box.

### `szHelpFileName`

A pointer to a null-terminated string that contains the full path to the Help file.

### `dwHelpId`

The context identifier for the topic. For more information, see
[WinHelp](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/winhelp).

### `hprov`

A handle to the
[Cryptographic Service Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-service-providers) (CSP)
to use for certificate verification.

## See also

[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea)

## Remarks

> [!NOTE]
> The cryptdlg.h header defines CERT_SELECT_STRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).