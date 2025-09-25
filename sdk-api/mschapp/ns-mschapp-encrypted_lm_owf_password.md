# ENCRYPTED_LM_OWF_PASSWORD structure

## Description

The **ENCRYPTED_LM_OWF_PASSWORD** stores a user's encrypted Lan Manager (LM) one-way function (OWF) password hash.

## Members

### `data`

An array of [CYPHER_BLOCK](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-cypher_block) structures that contain an encrypted LM OWF password hash. The contents of the array are calculated using the **OldLmPasswordHashEncryptedWithNewNtPasswordHash()** function as defined in [RFC 2433](https://www.ietf.org/rfc/rfc2433.txt), section A.16.

## Remarks

[ENCRYPTED_NT_OWF_PASSWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc325729(v=vs.85)) is an alias for this structure.

## See also

[MS-CHAP Password Management Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mschap/ms-chap-password-management-structures)

[MSChapSrvChangePassword2](https://learn.microsoft.com/previous-versions/windows/desktop/api/mschapp/nf-mschapp-mschapsrvchangepassword2)