# CRYPT_TIME_STAMP_REQUEST_INFO structure

## Description

The **CRYPT_TIME_STAMP_REQUEST_INFO** structure is used for time stamping. To add an authenticated attribute when signing an executable file to verify the date and time of the signature, a signed time stamp is requested from a time stamp server. The **CRYPT_TIME_STAMP_REQUEST_INFO** structure is used to get a time stamp. It contains the signature bits of the material being time stamped in the **Content** field.

## Members

### `pszTimeStampAlgorithm`

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that specifies the desired format of the time stamp, usually UTC.

### `pszContentType`

The OID of the Content Type of the content, usually DATA.

### `Content`

A [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded signature bits of the material being time stamped.

### `cAttribute`

The number of elements in the **rgAttribute** array.

### `rgAttribute`

Array of pointers to
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each holding an encoded attribute.

## See also

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))