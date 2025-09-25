# CTL_FIND_USAGE_PARA structure

## Description

The **CTL_FIND_USAGE_PARA** structure is a member of the
[CTL_FIND_SUBJECT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_subject_para) structure and it is used by
[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore).

## Members

### `cbSize`

The size, in bytes, of this structure.

### `SubjectUsage`

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure that includes a sequence of object identifiers to be matched when finding a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL).

A found CTL must contain all the usage object identifiers specified by the **SubjectUsage** member.

If the **cUsageIdentifier** member of this structure is zero, a CTL with any usage can be a match.

### `ListIdentifier`

Specified to restrict a search to a particular signer CTL list. Normally the **ListIdentifier** member will be zero, indicating that any **ListIdentifier** can be matched. If it is not zero, this **ListIdentifier** and the **ListIdentifier** in a CTL must match.

To match only CTLs that have no **ListIdentifier** the **cbData** member of **ListIdentifier** is set to CTL_FIND_NO_LIST_ID_CBDATA.

A CTL uses a **ListIdentifier** to distinguish among multiple CTLs created by the same issuer with the same **SubjectUsage**.

### `pSigner`

A pointer to a
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure that specifies the CTL signer to be matched. Only the issuer and serial number from the **CERT_INFO** are used to match a signer.

Set **pSigner** to **NULL** to match any signer. To match CTLs that do not have any signers, set **pSigner** to CTL_FIND_NO_SIGNER_PTR.

The CertEncodingType of the signer is obtained from the *dwMsgAndCertEncodingType* parameter of
[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore).

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CTL_FIND_SUBJECT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_subject_para)

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)