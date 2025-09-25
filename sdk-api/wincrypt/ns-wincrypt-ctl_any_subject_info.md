# CTL_ANY_SUBJECT_INFO structure

## Description

The **CTL_ANY_SUBJECT_INFO** structure contains a **SubjectAlgorithm** to be matched in the [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) and the **SubjectIdentifier** to be matched in one of the CTL entries in calls to
[CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl).

## Members

### `SubjectAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure containing the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of an algorithm type and any associated additional parameters. The **pszObjId** can be set to **NULL** to exclude a **SubjectAlgorithm** comparison.

### `SubjectIdentifier`

[BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) containing a unique identifier of the subject.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CTL_FIND_SUBJECT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_subject_para)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl)