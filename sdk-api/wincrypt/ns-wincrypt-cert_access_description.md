# CERT_ACCESS_DESCRIPTION structure

## Description

The **CERT_ACCESS_DESCRIPTION** structure is a member of a
[CERT_AUTHORITY_INFO_ACCESS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_authority_info_access) structure. It contains one instance of information about how to access information and services for either the subject or the issuer of a certificate that contains either the subject information access or the authority information access extension, respectively. For more information about these certificate extensions, see [RFC 3280](https://www.ietf.org/rfc/rfc3280.txt).

## Members

### `pszAccessMethod`

Specifies the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the method of access.

The following are currently defined PKIX Access Method OIDs:

* szOID_PKIX_CA_ISSUERS
* szOID_PKIX_CA_REPOSITORY
* szOID_PKIX_OCSP
* szOID_PKIX_TIME_STAMPING

The default provider does not support the szOID_PKIX_TIME_STAMPING method.

### `AccessLocation`

[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure that describes the online status server and the access protocol to obtain current certificate status information for the certificate containing the extension.

For the szOID_PKIX_OCSP access method, **AccessLocation** describes the online status server and the access protocol needed to obtain status information about the certificate containing this extension.

For the szOID_PKIX_CA_ISSUERS access method, **AccessLocation** obtains information on the CAs that issued certificates superior to the CA that issued the certificate containing this extension. The CA issuer's description is intended to aid certificate users in the selection of a certification path that terminates at a point trusted by the certificate user.

For the szOID_PKIX_CA_REPOSITORY method, **AccessLocation** specifies either the URI, directory name, or email address of the certificate and [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) repository for a subject that is a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA).

## See also

[CERT_AUTHORITY_INFO_ACCESS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_authority_info_access)

[RFC 3280](https://www.ietf.org/rfc/rfc3280.txt)