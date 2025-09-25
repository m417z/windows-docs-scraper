# CERT_NAME_VALUE structure

## Description

The **CERT_NAME_VALUE** structure contains a [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN) attribute value. It is like the
[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structure, except that it does not include the object identifier member that is a member of **CERT_RDN_ATTR**. As in **CERT_RDN_ATTR**, the interpretation of the **Value** member depends on **dwValueType**.

## Members

### `dwValueType`

Indicates the interpretation of the **Value** member. For documentation on possible values of **dwValueType**, see
[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr).

### `Value`

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the RDN attribute. The **cbData** member of **Value** is the length, in bytes, of the **pbData** member. It is not the number of elements in the **pbData** string.

For example, a **DWORD** is 32 bits or 4 bytes long. If the **pbData** member of **Value** is a **DWORD** array, the **cbData** member of **Value** would be four times the number of **DWORD** elements in the array. A **short** data type is 16 bits or 2 bytes long. If the **pbData** member is an array of **short** data types, the **cbData** member must be two times the length of the array.

The **pbData** member of **Value** can be a null-terminated array of 8-bit or 16-bit characters or a fixed-length array of elements. If **dwValueType** is set to CERT_RDN_ENCODED_BLOB, **pbData** is encoded.

## See also

[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn)

[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CertRDNValueToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certrdnvaluetostra)