# CRYPT_CONTENT_INFO structure

## Description

The **CRYPT_CONTENT_INFO** structure contains data encoded in the PKCS #7 ContentInfo data format.

## Members

### `pszObjId`

Object identifier (OID) of the type of data contained in the **Content** member. ContentType in PKCS #7 defines a set of predefined OIDs. However, additional OIDs can be defined and used.

### `Content`

The data encoded in the PKCS #7 ContentInfo data format.