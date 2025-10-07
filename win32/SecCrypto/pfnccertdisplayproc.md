# PFNCCERTDISPLAYPROC callback function

The **PFNCCERTDISPLAYPROC** function is a user-defined callback function that allows the caller of the [**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate) function to handle the display of certificates that the user selects to view.

## Parameters

*pCertContext* \[in\]

A pointer to a [**CERT\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context) structure that represents the certificate to display.

*hWndSelCertDlg* \[in\]

A handle to the dialog box from which the certificate was selected for viewing.

*pvCallbackData* \[in\]

Additional data used by the callback function.

## Return value

This function returns **TRUE** to indicate that it handles display of the certificate and that the dialog box should not display the certificate. If this function returns **FALSE**, the dialog box displays the certificate.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

