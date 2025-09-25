# WS_SECURITY_ALGORITHM_ID enumeration

## Description

Defines the security algorithms to be used with WS-Security.
These values are relevant to message security bindings
and mixed-mode security bindings.

## Constants

### `WS_SECURITY_ALGORITHM_DEFAULT:0`

Default security algorithm for the particular algorithm type. See
[WS_SECURITY_ALGORITHM_SUITE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_algorithm_suite) for a description of the
specific algorithm used when this value is set.

### `WS_SECURITY_ALGORITHM_CANONICALIZATION_EXCLUSIVE:1`

http://www.w3.org/2001/10/xml-exc-c14n#.

### `WS_SECURITY_ALGORITHM_CANONICALIZATION_EXCLUSIVE_WITH_COMMENTS:2`

http://www.w3.org/2001/10/xml-exc-c14n#WithComments.

### `WS_SECURITY_ALGORITHM_DIGEST_SHA1:3`

http://www.w3.org/2000/09/xmldsig#sha1.

### `WS_SECURITY_ALGORITHM_DIGEST_SHA_256:4`

http://www.w3.org/2001/04/xmlenc#sha256.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_DIGEST_SHA_384:5`

http://www.w3.org/2001/04/xmlenc#sha384.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_DIGEST_SHA_512:6`

http://www.w3.org/2001/04/xmlenc#sha512.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_SYMMETRIC_SIGNATURE_HMAC_SHA1:7`

http://www.w3.org/2000/09/xmldsig#hmac-sha1.

### `WS_SECURITY_ALGORITHM_SYMMETRIC_SIGNATURE_HMAC_SHA_256:8`

http://www.w3.org/2001/04/xmldsig-more#hmac-sha256.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_SYMMETRIC_SIGNATURE_HMAC_SHA_384:9`

http://www.w3.org/2001/04/xmldsig-more#hmac-sha384.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_SYMMETRIC_SIGNATURE_HMAC_SHA_512:10`

http://www.w3.org/2001/04/xmldsig-more#hmac-sha512.
Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_RSA_SHA1:11`

http://www.w3.org/2000/09/xmldsig#rsa-sha1.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_DSA_SHA1:12`

http://www.w3.org/2000/09/xmldsig#dsa-sha1.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_RSA_SHA_256:13`

http://www.w3.org/2001/04/xmldsig-more#rsa-sha256

Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_RSA_SHA_384:14`

http://www.w3.org/2001/04/xmldsig-more#rsa-sha384

Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_SIGNATURE_RSA_SHA_512:15`

http://www.w3.org/2001/04/xmldsig-more#rsa-sha512

Requires Windows 2003 Server SP1 or above.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_KEYWRAP_RSA_1_5:16`

http://www.w3.org/2001/04/xmlenc#rsa-1_5.

### `WS_SECURITY_ALGORITHM_ASYMMETRIC_KEYWRAP_RSA_OAEP:17`

http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p.

### `WS_SECURITY_ALGORITHM_KEY_DERIVATION_P_SHA1:18`

http://schemas.xmlsoap.org/ws/2005/02/sc/dk/p_sha1.