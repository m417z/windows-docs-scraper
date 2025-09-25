# CRYPT_ATTRIBUTE_TYPE_VALUE structure

## Description

The **CRYPT_ATTRIBUTE_TYPE_VALUE** structure contains a single attribute value. The **Value** member's [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) is encoded.

## Members

### `pszObjId`

[Object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that specifies the attribute type data contained in the **Value** BLOB.

### `Value`

A [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the encoded attribute. The **cbData** member of the **CRYPT_OBJID_BLOB** structure indicates the length of the **pbData** member. The **pbData** member contains the attribute information.

## See also

[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))