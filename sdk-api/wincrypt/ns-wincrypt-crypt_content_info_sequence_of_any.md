# CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY structure

## Description

The **CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY** structure contains information representing the Netscape certificate sequence of certificates.

A Netscape certificate sequence of certificates can be created by setting the **pszObjId** member to szOID_NETSCAPE_CERT_SEQUENCE and supplying [DER](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly)-encoded certificates in **rgValue**.

## Members

### `pszObjId`

Object identifier (OID) specifying the type of data contained in the **rgValue** array.

### `cValue`

Number of elements in the **rgValue** array.

### `rgValue`

Array of pointers to [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures. For more information, see
[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).