# CTL_FIND_SUBJECT_PARA structure

## Description

The **CTL_FIND_SUBJECT_PARA** structure contains data used by
[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore) with a *dwFindType* parameter of CTL_FIND_SUBJECT to find a [Certificate Trust List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL).

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pUsagePara`

A pointer to a
[CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para) structure. Can be **NULL** if there is no need to reference the **CTL_FIND_USAGE_PARA** parameters when finding a CTL.

### `dwSubjectType`

For CTL_CERT_SUBJECT_TYPE, the **pvSubject** member points to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). The CTL's **SubjectAlgorithm** is examined to determine the representation of the subject's identity. Initially, only SHA1 or MD5 hash will be supported. The appropriate hash property is obtained from the **CERT_CONTEXT**.

For CTL_ANY_SUBJECT_TYPE, **pvSubject** points to the
[CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info) structure that contains the **SubjectAlgorithm** to be matched in the CTL and the **SubjectIdentifier** to be matched in one of the CTL entries.

### `pvSubject`

The value of the **pvSubject** member depends upon the value of the **dwSubjectType** member. For more information, see **dwSubjectType**.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info)

[CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)