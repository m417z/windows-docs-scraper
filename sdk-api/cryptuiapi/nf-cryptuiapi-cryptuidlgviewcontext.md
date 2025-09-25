# CryptUIDlgViewContext function

## Description

The **CryptUIDlgViewContext** function displays a certificate, CTL, or CRL context.

## Parameters

### `dwContextType` [in]

**DWORD** indicating whether *pvContext* is a pointer to a certificate, a CRL, or a CTL context as indicated in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_CERTIFICATE_CONTEXT** | PCCERT_CONTEXT |
| **CERT_STORE_CRL_CONTEXT** | PCCRL_CONTEXT |
| **CERT_STORE_CTL_CONTEXT** | PCCTL_CONTEXT |

### `pvContext` [in]

A pointer to a certificate, CRL, or CTL context to be displayed.

### `hwnd` [in]

Handle of the window for the display. If **NULL**, the display defaults to the desktop window.

### `pwszTitle` [in]

Display title string. If **NULL**, the default context type is used as the title.

### `dwFlags` [in]

Currently not used and should be set to 0.

### `pvReserved` [in]

Reserved for future use.

## Return value

This function returns **TRUE** on success and **FALSE** on failure.

## See also

[CryptUIDlgSelectCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgselectcertificatefromstore)