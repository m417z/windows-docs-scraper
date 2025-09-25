# LM_OWF_PASSWORD structure

## Description

The **LM_OWF_PASSWORD** stores the Lan Manage (LM) one-way function (OWF) of a user's password.

## Members

### `data`

An array of [CYPHER_BLOCK](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-cypher_block) structures that contain a LM OWF password hash. The contents of the array are calculated using the **LmEncryptedPasswordHash()** function as defined in [RFC 2433](https://www.ietf.org/rfc/rfc2433.txt), section A.8.

## Remarks

[NT_OWF_PASSWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc325731(v=vs.85)) is an alias for this structure.

## See also

[MS-CHAP Password Management Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mschap/ms-chap-password-management-structures)

[MSChapSrvChangePassword](https://learn.microsoft.com/previous-versions/windows/desktop/api/mschapp/nf-mschapp-mschapsrvchangepassword)