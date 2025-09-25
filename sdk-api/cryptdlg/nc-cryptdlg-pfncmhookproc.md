# PFNCMHOOKPROC callback function

## Description

The **PFNCMHOOKPROC** function is a hook procedure that is called before messages are processed by the certificate selection dialog box produced by the [CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function. The function allows the caller to customize the dialog box. **PFNCMHOOKPROC** is an application-defined callback function specified in the [CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a) structure. The **CERT_SELECT_STRUCT** structure is a parameter in the [CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function. The **PFNCMHOOKPROC** function must be implemented by the developer to suit each application.

## Parameters

### `hwndDialog` [in]

A handle to a dialog box window.

### `message` [in]

The message.

### `wParam` [in]

Additional information about the message sent or posted.

### `lParam` [in]

 Additional information about the message sent or posted.

## Return value

Return a nonzero value (**TRUE**) if this function processes the message. Return zero (**FALSE**) if this function does not process the message.

## Remarks

For information about hooks, see [Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks).

## See also

[CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a)

[CertSelectCertificate](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certselectcertificatea)