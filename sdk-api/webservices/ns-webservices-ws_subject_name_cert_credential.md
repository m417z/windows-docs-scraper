# WS_SUBJECT_NAME_CERT_CREDENTIAL structure

## Description

The type for specifying a certificate credential using the
certificate's subject name, store location and store name. The
specified credential is loaded when the containing channel or listener
is opened.

## Members

### `credential`

The base type from which this type and all other certificate credential types derive.

### `storeLocation`

The certificate store location (such as CERT_SYSTEM_STORE_CURRENT_USER
or CERT_SYSTEM_STORE_LOCAL_MACHINE) that contains the specified
certificate.

### `storeName`

The certificate store name (such as "My") that contains the specified
certificate.

### `subjectName`

The subject name (such as "CN=service.com") of the specified
certificate. The supplied subject name string must be in a format acceptable to
CERT_FIND_SUBJECT_NAME-based
search.
(See [CertFindCertificateInStore](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-certfindcertificateinstore).)