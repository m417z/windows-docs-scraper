# CTL_VERIFY_USAGE_STATUS structure

## Description

The **CTL_VERIFY_USAGE_STATUS** structure contains information about a [Certificate Trust List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) returned by
[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage).

## Members

### `cbSize`

The size, in bytes, of the structure. The application calling
[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage) sets this parameter. If **cbSize** is not greater than or equal to the required size of the structure, **CertVerifyCTLUsage** returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **E_INVALIDARG**.

### `dwError`

The error status, if any, returned by the call to [CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage). For the list of possible error values, see the Return Values section in **CertVerifyCTLUsage**.

### `dwFlags`

If **CERT_VERIFY_UPDATED_CTL_FLAG** is returned, [CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage) updated a CTL whose time was no longer valid with a new, time-valid CTL.

### `ppCtl`

Pointer to a pointer to a CTL [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) containing the matched subject. The calling application can set this pointer to **NULL** to indicate that a CTL containing the subject is not to be returned.

If **ppCtl** is not **NULL**, the calling application must free the returned context using [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

### `dwCtlEntryIndex`

Returns the array location of the matching subject's entry in the CTL's array.

### `ppSigner`

A pointer to a pointer to the certificate context of the signer of the CTL. This pointer can be set to **NULL** by the calling application indicating that the certificate of the signer of the CTL is not to be returned.

If **ppSigner** is not **NULL**, the calling application must free the returned context using [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

### `dwSignerIndex`

Index of the signer actually used. Needed if a message has more than one signer.

## Remarks

The members **dwError**, **dwFlags**, **dwCtlEntryIndex**, and **dwSignerIndex** should be initialized to zero by the calling application.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage)